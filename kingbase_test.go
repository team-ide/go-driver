package go_driver

import (
	"context"
	"fmt"
	"gitee.com/chunanyong/zorm"
	"github.com/team-ide/go-driver/db_kingbase_v8r6"
	"testing"
)

func TestKinBase(t *testing.T) {
	//dbConfig := db_kingbase_v8r3.NewDataSourceConfig("SYSTEM", "123456", "127.0.0.1", 54321, "TEST")
	dbConfig := db_kingbase_v8r6.NewDataSourceConfig("SYSTEM", "123456", "127.0.0.1", 54321, "TEST")
	sql := `select 2`
	dbDao, err := zorm.NewDBDao(&dbConfig)
	if err != nil {
		panic(err)
	}

	cxt := context.Background()
	cxt, err = dbDao.BindContextDBConnection(cxt)
	if err != nil {
		panic(err)
	}
	finder := zorm.NewFinder()
	finder.Append(sql)

	var count int
	_, err = zorm.QueryRow(cxt, finder, &count)
	fmt.Printf("result:%d\n", count)
	if count == 2 {
		fmt.Println("test success")
	} else {
		panic("test fail")
	}
}
