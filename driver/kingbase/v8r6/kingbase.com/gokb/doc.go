/*
Package kb is a pure Go Kingbase driver for the database/sql package.

In most cases clients will use the database/sql package instead of
using this package directly. For example:

	import (
		"database/sql"

		_ "kingbase.com/gokb"
	)

	func main() {
		connStr := "user=kbgotest dbname=kbgotest sslmode=verify-full"
		db, err := sql.Open("kingbase", connStr)
		if err != nil {
			log.Fatal(err)
		}

		age := 21
		rows, err := db.Query("SELECT name FROM users WHERE age = $1", age)
		…
	}

You can also connect to a database using a URL. For example:

	connStr := "kingbase://kbgotest:password@localhost/kbgotest?sslmode=verify-full"
	db, err := sql.Open("kingbase", connStr)


Connection String Parameters


Similarly to libkci, when establishing a connection using kb you are expected to
supply a connection string containing zero or more parameters.
A subset of the connection parameters supported by libkci are also supported by kb.
Additionally, kb also lets you specify run-time parameters (such as search_path or work_mem)
directly in the connection string.  This is different from libkci, which does not allow
run-time parameters in the connection string, instead requiring you to supply
them in the options parameter.

For compatibility with libkci, the following special connection parameters are
supported:

	* dbname - The name of the database to connect to
	* user - The user to sign in as
	* password - The user's password
	* host - The host to connect to. Values that start with / are for unix
	  domain sockets. (default is localhost)
	* port - The port to bind to. (default is 54321)
	* sslmode - Whether or not to use SSL (default is require, this is not
	  the default for libkci)
	* fallback_application_name - An application_name to fall back to if one isn't provided.
	* connect_timeout - Maximum wait for connection, in seconds. Zero or
	  not specified means wait indefinitely.
	* sslcert - Cert file location. The file must contain PEM encoded data.
	* sslkey - Key file location. The file must contain PEM encoded data.
	* sslrootcert - The location of the root certificate file. The file
	  must contain PEM encoded data.

Valid values for sslmode are:

	* disable - No SSL
	* require - Always SSL (skip verification)
	* verify-ca - Always SSL (verify that the certificate presented by the
	  server was signed by a trusted CA)
	* verify-full - Always SSL (verify that the certification presented by
	  the server was signed by a trusted CA and the server host name
	  matches the one in the certificate)

See http://www.kingbase.org/docs/current/static/libkci-connect.html#LIBPQ-CONNSTRING
for more information about connection string parameters.

Use single quotes for values that contain whitespace:

    "user=kbgotest password='with spaces'"

A backslash will escape the next character in values:

    "user=space\ man password='it\'s valid'"

Note that the connection parameter client_encoding (which sets the
text encoding for the connection) may be set but must be "UTF8",
matching with the same rules as Kingbase. It is an error to provide
any other value.

In addition to the parameters listed above, any run-time parameter that can be
set at backend start time can be set in the connection string.  For more
information, see
http://www.kingbase.org/docs/current/static/runtime-config.html.

Most environment variables as specified at http://www.kingbase.org/docs/current/static/libkci-envars.html
supported by libkci are also supported by kb.  If any of the environment
variables not supported by kb are set, kb will panic during connection
establishment.  Environment variables have a lower precedence than explicitly
provided connection parameters.

The kbpass mechanism as described in http://www.kingbase.org/docs/current/static/libkci-kbpass.html
is supported, but on Windows KBPASSFILE must be specified explicitly.


Queries


database/sql does not dictate any specific format for parameter
markers in query strings, and kb uses the Kingbase-native ordinal markers,
as shown above. The same marker can be reused for the same parameter:

	rows, err := db.Query(`SELECT name FROM users WHERE favorite_fruit = $1
		OR age BETWEEN $2 AND $2 + 3`, "orange", 64)

kb does not support the LastInsertId() method of the Result type in database/sql.
To return the identifier of an INSERT (or UPDATE or DELETE), use the Kingbase
RETURNING clause with a standard Query or QueryRow call:

	var userid int
	err := db.QueryRow(`INSERT INTO users(name, favorite_fruit, age)
		VALUES('beatrice', 'starfruit', 93) RETURNING id`).Scan(&userid)

For more details on RETURNING, see the Kingbase documentation:

	http://www.kingbase.org/docs/current/static/sql-insert.html
	http://www.kingbase.org/docs/current/static/sql-update.html
	http://www.kingbase.org/docs/current/static/sql-delete.html

For additional instructions on querying see the documentation for the database/sql package.


Data Types


Parameters pass through driver.DefaultParameterConverter before they are handled
by this package. When the binary_parameters connection option is enabled,
[]byte values are sent directly to the backend as data in binary format.

This package returns the following types for values from the Kingbase backend:

	- integer types smallint, integer, and bigint are returned as int64
	- floating-point types real and double precision are returned as float64
	- character types char, varchar, and text are returned as string
	- temporal types date, time, timetz, timestamp, and timestamptz are
	  returned as time.Time
	- the boolean type is returned as bool
	- the bytea type is returned as []byte

All other types are returned directly from the backend as []byte values in text format.


Errors


kb may return errors of type *kb.Error which can be interrogated for error details:

        if err, ok := err.(*kb.Error); ok {
            fmt.Println("kb error:", err.Code.Name())
        }

See the kb.Error type for details.


Bulk imports

You can perform bulk imports by preparing a statement returned by kb.CopyIn (or
kb.CopyInSchema) in an explicit transaction (sql.Tx). The returned statement
handle can then be repeatedly "executed" to copy data into the target table.
After all data has been processed you should call Exec() once with no arguments
to flush all buffered data. Any call to Exec() might return an error which
should be handled appropriately, but because of the internal buffering an error
returned by Exec() might not be related to the data passed in the call that
failed.

CopyIn uses COPY FROM internally. It is not possible to COPY outside of an
explicit transaction in kb.

Usage example:

	txn, err := db.Begin()
	if err != nil {
		log.Fatal(err)
	}

	stmt, err := txn.Prepare(kb.CopyIn("users", "name", "age"))
	if err != nil {
		log.Fatal(err)
	}

	for _, user := range users {
		_, err = stmt.Exec(user.Name, int64(user.Age))
		if err != nil {
			log.Fatal(err)
		}
	}

	_, err = stmt.Exec()
	if err != nil {
		log.Fatal(err)
	}

	err = stmt.Close()
	if err != nil {
		log.Fatal(err)
	}

	err = txn.Commit()
	if err != nil {
		log.Fatal(err)
	}


Notifications


Kingbase supports a simple publish/subscribe model over database
connections.  See http://www.kingbase.org/docs/current/static/sql-notify.html
for more information about the general mechanism.

To start listening for notifications, you first have to open a new connection
to the database by calling NewListener.  This connection can not be used for
anything other than LISTEN / NOTIFY.  Calling Listen will open a "notification
channel"; once a notification channel is open, a notification generated on that
channel will effect a send on the Listener.Notify channel.  A notification
channel will remain open until Unlisten is called, though connection loss might
result in some notifications being lost.  To solve this problem, Listener sends
a nil pointer over the Notify channel any time the connection is re-established
following a connection loss.  The application can get information about the
state of the underlying connection by setting an event callback in the call to
NewListener.

A single Listener can safely be used from concurrent goroutines, which means
that there is often no need to create more than one Listener in your
application.  However, a Listener is always connected to a single database, so
you will need to create a new Listener instance for every database you want to
receive notifications in.

The channel name in both Listen and Unlisten is case sensitive, and can contain
any characters legal in an identifier (see
http://www.kingbase.org/docs/current/static/sql-syntax-lexical.html#SQL-SYNTAX-IDENTIFIERS
for more information).  Note that the channel name will be truncated to 63
bytes by the Kingbase server.

You can find a complete, working example of Listener usage at
https://godoc.org/kingbase.com/gokb/example/listen.

*/
package gokb
