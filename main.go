package main

import (
	"database/sql"
	"flag"
	"fmt"
	"github.com/team-ide/go-driver/db_dm"
	"github.com/team-ide/go-driver/db_kingbase_v8r6"
	"github.com/team-ide/go-driver/db_mysql"
	"github.com/team-ide/go-driver/db_odbc"
	"github.com/team-ide/go-driver/db_oracle"
	"github.com/team-ide/go-driver/db_postgresql"
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
	if *dbType != "sqlite3" && *dbType != "odbc" {
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
	var db *sql.DB
	var sqlInfo string
	var err error
	switch *dbType {
	case "mysql":
		dsn := db_mysql.GetDSN(*user, *password, *host, *port, *database)
		db, err = db_mysql.Open(dsn)
		sqlInfo = `select 2`
		break
	case "sqlite3":
		dsn := db_sqlite3.GetDSN(*database)
		db, err = db_sqlite3.Open(dsn)
		sqlInfo = `select 2`
		break
	case "dm":
		dsn := db_dm.GetDSN(*user, *password, *host, *port)
		db, err = db_dm.Open(dsn)
		sqlInfo = `select 2`
		break
	case "kingbase":
		dsn := db_kingbase_v8r6.GetDSN(*user, *password, *host, *port, *database)
		db, err = db_kingbase_v8r6.Open(dsn)
		sqlInfo = `select 2`
		break
	case "oracle":
		dsn := db_oracle.GetDSN(*user, *password, *host, *port, *database)
		db, err = db_oracle.Open(dsn)
		sqlInfo = `select 2 from dual`
		break
	case "shentong":
		dsn := db_shentong.GetDSN(*user, *password, *host, *port, *database)
		db, err = db_shentong.Open(dsn)
		sqlInfo = `select 2`
		break
	case "postgresql":
		dsn := db_postgresql.GetDSN(*user, *password, *host, *port, *database)
		db, err = db_postgresql.Open(dsn)
		sqlInfo = `select 2`
		break
	case "odbc":
		dsn := db_odbc.GetDSN(*database, *user, *password)
		db, err = db_odbc.Open(dsn)
		sqlInfo = `select 2`
		break
	}
	if err != nil {
		panic(err)
	}
	connDb(db, sqlInfo)

}

func connDb(db *sql.DB, sql string) {
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
