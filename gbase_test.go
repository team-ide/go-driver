package main

import (
	"fmt"
	"github.com/team-ide/go-driver/db_gbase"
	"testing"
)

func TestGBase(t *testing.T) {
	dsn := `DRIVER=com.gbasebt.jdbc.Driver;NEWCODESET=UTF8,zh_cn.UTF8,57372;DB_LOCALE=zh_cn.57372;DELIMIDENT=Y;CLIENT_LOCALE=zh_cn.57372;ServerName=gbase01;host=127.0.0.1;service=9088;uid=gbasedbt;pwd=GBase123;DATABASE=VRV_JOB1;`
	db, err := db_gbase.Open(dsn)
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
