package db_odbc

import (
	"database/sql"
	"fmt"
	_ "github.com/team-ide/go-driver/driver/odbc"
)

func GetDriverName() string {
	return "odbc"
}

func GetDialect() string {
	return "gbase"
}

func GetDSN(database string, user string, password string) string {
	dsn := fmt.Sprintf("DSN=%s;UID=%s;PWD=%s", database, user, password)
	return dsn
}

func Open(dsn string) (db *sql.DB, err error) {
	db, err = sql.Open(GetDriverName(), dsn)
	if err != nil {
		return
	}
	return
}
