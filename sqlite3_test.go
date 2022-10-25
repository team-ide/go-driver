package main

import (
	"fmt"
	"github.com/team-ide/go-driver/db_sqlite3"
	"testing"
)

func TestSqlite3(t *testing.T) {

	dsn := db_sqlite3.GetDSN("test-sqlite3")
	db, err := db_sqlite3.Open(dsn)
	if err != nil {
		panic(err)
	}
	sql := `select 2`
	var count int
	rows, err := db.Query(sql)
	if err != nil {
		panic(err)
	}
	rows.Next()
	err = rows.Scan(&count)
	if err != nil {
		panic(err)
	}
	fmt.Printf("result:%d\n", count)
	if count == 2 {
		fmt.Println("test success")
	} else {
		panic("test fail")
	}
}
