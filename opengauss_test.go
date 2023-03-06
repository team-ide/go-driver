package main

import (
	"fmt"
	"github.com/team-ide/go-driver/db_opengauss"
	"testing"
)

func TestDb(t *testing.T) {

	dsn := db_opengauss.GetDSN("gaussdb", "Enmo@1234", "127.0.0.1", 5432, "postgres")
	db, err := db_opengauss.Open(dsn)
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
