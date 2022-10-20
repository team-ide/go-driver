package go_driver

import (
	"context"
	"fmt"
	"gitee.com/chunanyong/zorm"
	"github.com/team-ide/go-driver/db_oracle"
	"net"
	"testing"
)

func TestOracle(t *testing.T) {
	dbConfig := db_oracle.NewDataSourceConfig("root", "123456", "127.0.0.1", 1521, "xe")
	testConfig(dbConfig, `SELECT COUNT(*) FROM USER_TABLES`)
}

func TestConn(t *testing.T) {
	_, err := net.DialTimeout("tcp", "127.0.0.1:5236", 0)
	if err != nil {
		panic(err)
	}
}

func testConfig(dbConfig zorm.DataSourceConfig, sql string) {
	// 记录异常日志的函数
	zorm.FuncLogError = func(ctx context.Context, err error) {
		fmt.Println("sql error:", err)
		panic(err)
	}

	// 记录panic日志,默认使用defaultLogError实现
	zorm.FuncLogPanic = func(ctx context.Context, err error) {
		fmt.Println("sql panic:", err)
		panic(err)
	}
	// 打印sql的函数
	zorm.FuncPrintSQL = func(ctx context.Context, sqlstr string, args []interface{}, execSQLMillis int64) {
		fmt.Printf("sql :%s\n", sqlstr)
		fmt.Printf("args:%s\n", args)
	}
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
}
