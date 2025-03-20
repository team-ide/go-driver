package main

import (
	"database/sql"
	"fmt"
	"github.com/team-ide/go-driver/db_dm"
	"github.com/team-ide/go-driver/db_kingbase_v8r3"
	"github.com/team-ide/go-driver/db_kingbase_v8r6"
	"github.com/team-ide/go-driver/db_mysql"
	"github.com/team-ide/go-driver/db_shentong"
	"github.com/team-ide/go-driver/db_ux"
	"testing"
)

var (
	testPassword = `1@2\3'4/5%n K#$%^&*()_+!1?6:34`
)

func dbPing(db *sql.DB) {
	err := db.Ping()
	if err != nil {
		fmt.Println("error:", err)
		return
	}
	_ = db.Close()
}
func TestKingBaseR3Password(t *testing.T) {
	fmt.Println("test password:", testPassword)
	dsn := db_kingbase_v8r3.GetDSN("SYSTEM", testPassword, "127.0.0.1", 54321, "TEST")
	db, err := db_kingbase_v8r3.Open(dsn)
	if err != nil {
		fmt.Println("error:", err)
		return
	}
	dbPing(db)
}

func TestKingBaseV6Password(t *testing.T) {
	fmt.Println("test password:", testPassword)
	dsn := db_kingbase_v8r6.GetDSN("SYSTEM", testPassword, "127.0.0.1", 54321, "TEST")
	db, err := db_kingbase_v8r6.Open(dsn)
	if err != nil {
		fmt.Println("error:", err)
		return
	}
	dbPing(db)
}

func TestShenTongPassword(t *testing.T) {
	fmt.Println("test password:", testPassword)
	dsn := db_shentong.GetDSN("SYSTEM", testPassword, "127.0.0.1", 54321, "TEST")
	dsn += "?reconnect_timeout=1&call_timeout=1&socket_connect_timeout=1"
	db, err := db_shentong.Open(dsn)
	if err != nil {
		fmt.Println("error:", err)
		return
	}
	dbPing(db)
}

func TestDmPassword(t *testing.T) {
	fmt.Println("test password:", testPassword)
	dsn := db_dm.GetDSN("SYSTEM", testPassword, "127.0.0.1", 54321, "TEST")
	db, err := db_dm.Open(dsn)
	if err != nil {
		fmt.Println("error:", err)
		return
	}
	dbPing(db)
}

func TestUxPassword(t *testing.T) {
	fmt.Println("test password:", testPassword)
	dsn := db_ux.GetDSN("SYSTEM", testPassword, "127.0.0.1", 54321, "TEST")
	db, err := db_ux.Open(dsn)
	if err != nil {
		fmt.Println("error:", err)
		return
	}
	dbPing(db)
}

func TestMysqlPassword(t *testing.T) {
	fmt.Println("test password:", testPassword)
	dsn := db_mysql.GetDSN("test1", testPassword, "127.0.0.1", 3306, "")
	db, err := db_mysql.Open(dsn)
	if err != nil {
		fmt.Println("error:", err)
		return
	}
	dbPing(db)
}
