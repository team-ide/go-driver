package main

import (
	"fmt"
	"github.com/team-ide/go-driver/db_oracle"
	"testing"
)

func TestOracle(t *testing.T) {

	dsn := db_oracle.GetDSN("root", "123456", "127.0.0.1", 1521, "xe")
	db, err := db_oracle.Open(dsn)
	if err != nil {
		panic(err)
	}
	sql := `select 2 from dual`
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
