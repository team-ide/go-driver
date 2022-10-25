package main

import (
	"fmt"
	"github.com/team-ide/go-driver/db_kingbase_v8r6"
	"testing"
)

func TestKingBase(t *testing.T) {
	dsn := db_kingbase_v8r6.GetDSN("SYSTEM", "123456", "127.0.0.1", 54321, "TEST")
	db, err := db_kingbase_v8r6.Open(dsn)
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
