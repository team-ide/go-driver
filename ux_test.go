package main

import (
	"fmt"
	"github.com/team-ide/go-driver/db_ux"
	"testing"
)

func TestUx(t *testing.T) {

	dsn := db_ux.GetDSN("test_db1", "TEST_DB1", "192.168.0.110", 5432, "uxdb")
	db, err := db_ux.Open(dsn)
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
