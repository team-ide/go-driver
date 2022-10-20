package go_driver

import (
	"context"
	"fmt"
	"gitee.com/chunanyong/zorm"
	"github.com/team-ide/go-driver/db_shentong"
	"testing"
)

/**
set PKG_CONFIG_PATH="C:\Workspaces\Code\teamide\go-driver\driver\shentong\go_aci-1.0.8.noarch.publish\drivers\go-aci"
*/
func TestShenTong(t *testing.T) {
	dbConfig := db_shentong.NewDataSourceConfig("SYSDBA", "szoscar55", "192.168.6.142", 2003, "OSRDB")
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
