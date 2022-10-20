package main

import (
	"database/sql"
	"fmt"
	"io"
	"log"
	"os"
	"strings"
	"testing"
)

var (
	Debug   *log.Logger
	Info    *log.Logger
	Warning *log.Logger
	Error   *log.Logger
)

var LogPath string
var LogFile *os.File

func init() {
	logFile, err := os.OpenFile("./log.txt", os.O_CREATE|os.O_WRONLY|os.O_APPEND, 0666)
	if err != nil {
		log.Fatalln("打开日志文件失败：", err)
	}

	Debug = log.New(io.MultiWriter(os.Stdout, logFile), "Debug:", log.Ldate|log.Ltime|log.Lshortfile)
	Info = log.New(io.MultiWriter(os.Stdout, logFile), "Info:", log.Ldate|log.Ltime|log.Lshortfile)
	Warning = log.New(io.MultiWriter(os.Stdout, logFile), "Warning:", log.Ldate|log.Ltime|log.Lshortfile)
	Error = log.New(io.MultiWriter(os.Stderr, logFile), "Error:", log.Ldate|log.Ltime|log.Lshortfile)
}

var global_db *sql.DB
var host string
var port string
var user string
var password string
var dbname string

func setup() {
	// args := os.Args
	// Debug.Println(args)
	Debug.Println("setup...")
	host = os.Getenv("host")
	port = os.Getenv("port")
	dbname = os.Getenv("db")
	user = os.Getenv("username")
	password = os.Getenv("password")

	dsn := fmt.Sprintf("%s/%s@%s:%s/%s", user, password, host, port, dbname) //SYSDBA:szoscar55@localhost:2003/OSRDB
	Debug.Println(dsn)
	db, err := sql.Open("aci", dsn)

	if err != nil {
		Error.Println(err)
		os.Exit(1)
	}
	global_db = db
}

func tearDown() {
	fmt.Println("tearDown...")
	// Debug.Println("tearDown...")
	// M := global_db.Migrator()
	// M.DropTable(&User{})
	// M.DropTable(&Student{})
}

func TestMain(m *testing.M) {
	setup()
	code := m.Run()
	tearDown()
	os.Exit(code)
}

func TestConnect(t *testing.T) {
	// if len(os.Args) != 2 {
	// 	log.Fatalln(os.Args[0] + " user/password@host:port/sid")
	// }

	defer global_db.Close()

	_, err := global_db.Exec("CREATE TABLE TEST (A NUMBER(100,0),B VARCHAR2(100))")
	if err != nil {
		Error.Println(err)
		// os.Exit(1)
	}
	insertsql := "insert into test values(:1,:2)"
	stmt, err := global_db.Prepare(insertsql)
	stmt.Exec(1, 6666)
	//stmt.Exec(2,bytes.Repeat([]byte("abcdefghijklmnopqrstuvwxyz"), 200))
	stmt.Exec(2, strings.Repeat("abcdefghijklmnopqrstuvwxyz", 2))
	//stmt.Exec()

	rows, err := global_db.Query("select b from test")
	if err != nil {
		Error.Println(err)
		t.Fail() //标志测试用例失败，但不退出程序
	}
	defer rows.Close()

	for rows.Next() {
		var data string
		rows.Scan(&data)
		fmt.Println(data)
	}
	if err = rows.Err(); err != nil {
		Error.Println(err)
		t.Fail()
	}
}

func TestDSN1(t *testing.T) {
	dsn := fmt.Sprintf("%s/%s@%s:%s/%s", user, password, host, port, dbname) + "?trace_level=2;fetch_size=17"
	db, err := sql.Open("aci", dsn)
	defer db.Close()
	if err != nil {
		Error.Println(err)
		t.Fail()
	}

	_, err = db.Query("select b from test")
	if err != nil {
		Error.Println(err)
		t.Fail()
	}
}

func TestDSN2(t *testing.T) {
	dsn := fmt.Sprintf("%s/%s@%s:%s/%s", user, password, host, port, dbname) + "?trace_level=2;fetch_size1=17"
	Debug.Println(dsn)
	db, err := sql.Open("aci", dsn)
	defer db.Close()
	if err != nil {
		Error.Println(err)
		t.Fail()
	}

	_, err = db.Query("select b from test")
	if err != nil {
		Error.Println(err)
		t.Fail()
	}
}

func TestDSN3(t *testing.T) {
	dsn := fmt.Sprintf("%s/%s@%s:%s/%s", user, password, host, port, dbname) + "?TRace_level=2;Fetch_size=17"
	Debug.Println(dsn)
	db, err := sql.Open("aci", dsn)
	defer db.Close()
	if err != nil {
		Error.Println(err)
		t.Fail()
	}

	_, err = db.Query("select b from test")
	if err != nil {
		Error.Println(err)
		t.Fail()
	}
}

func TestDSN4(t *testing.T) {
	dsn := fmt.Sprintf("%s/%s@%s:%s/%s", user, password, host, port, dbname) + "?TRace_level11=2;Fetch_size=17"
	Debug.Println(dsn)
	db, err := sql.Open("aci", dsn)
	defer db.Close()
	if err != nil {
		Error.Println(err)
		t.Fail()
	}

	_, err = db.Query("select b from test")
	if err != nil {
		Error.Println(err)
		t.Fail()
	}
}
