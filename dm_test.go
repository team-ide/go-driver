package main

import (
	"fmt"
	"github.com/team-ide/go-driver/db_dm"
	"testing"
)

func TestDm(t *testing.T) {
	dsn := db_dm.GetDSN("SYSDBA", "SYSDBA", "192.168.0.53", 55236, "")
	db, err := db_dm.Open(dsn)
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
