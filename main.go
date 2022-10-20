package main

import (
	"context"
	"flag"
	"fmt"
	"gitee.com/chunanyong/zorm"
	"github.com/team-ide/go-driver/db_dm"
	"github.com/team-ide/go-driver/db_kingbase_v8r6"
	"github.com/team-ide/go-driver/db_mysql"
	"github.com/team-ide/go-driver/db_oracle"
	"github.com/team-ide/go-driver/db_shentong"
	"github.com/team-ide/go-driver/db_sqlite3"
)

var (
	dbType   = flag.String("t", "", "数据库类型：mysql、sqlite3、dm、kingbase、oracle")
	host     = flag.String("h", "", "数据库Host")
	port     = flag.Int("p", 0, "数据库Port")
	user     = flag.String("u", "", "数据库登录用户")
	password = flag.String("P", "", "数据库登录密码")
	database = flag.String("d", "", "数据库模式名称")
)

func main() {
	flag.Parse()

	flag.PrintDefaults()
	if *dbType == "" {
		println("请输入 数据库类型")
		return
	}
	if *dbType != "sqlite3" {
		if *host == "" {
			println("请输入 数据库Host")
			return
		}
		if *port == 0 {
			println("请输入 数据库Port")
			return
		}
		if *user == "" {
			flag.PrintDefaults()
			println("请输入 数据库登录用户")
			return
		}
	}
	var dbConfig zorm.DataSourceConfig
	var sql string
	switch *dbType {
	case "mysql":
		dbConfig = db_mysql.NewDataSourceConfig(*user, *password, *host, *port, *database)
		sql = `select 2`
		break
	case "sqlite3":
		dbConfig = db_sqlite3.NewDataSourceConfig(*database)
		sql = `select 2`
		break
	case "dm":
		dbConfig = db_dm.NewDataSourceConfig(*user, *password, *host, *port)
		sql = `select 2`
		break
	case "kingbase":
		dbConfig = db_kingbase_v8r6.NewDataSourceConfig(*user, *password, *host, *port, *database)
		sql = `select 2`
		break
	case "oracle":
		dbConfig = db_oracle.NewDataSourceConfig(*user, *password, *host, *port, *database)
		sql = `select 2 from dual`
		break
	case "shentong":
		dbConfig = db_shentong.NewDataSourceConfig(*user, *password, *host, *port, *database)
		sql = `select 2`
		break
	}
	connDb(dbConfig, sql)

}

func connDb(dbConfig zorm.DataSourceConfig, sql string) {
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
