package db_kingbase_v8r6

import (
	"database/sql"
	"fmt"
	"net/url"

	//_ "github.com/lib/pq"
	_ "github.com/team-ide/go-driver/driver/kingbase/v8r6/kingbase.com/gokb"
)

func GetDriverName() string {
	return "v8r6-kingbase"
}

func GetDialect() string {
	return "kingbase"
}

func GetDSN(user string, password string, host string, port int, database string) string {
	password = url.PathEscape(password)
	dsn := fmt.Sprintf("kingbase://%s:%s@%s:%d/%s?sslmode=disable", user, password, host, port, database)
	return dsn
}

func Open(dsn string) (db *sql.DB, err error) {
	db, err = sql.Open(GetDriverName(), dsn)
	if err != nil {
		return
	}
	return
}

//func NewDataSourceConfig(user string, password string, host string, port int, database string) zorm.DataSourceConfig {
//	dsn := GetDSN(user, password, host, port, database)
//
//	dbDaoConfig := zorm.DataSourceConfig{
//		//DSN 数据库的连接字符串
//		DSN: dsn,
//		//数据库驱动名称:mysql,postgres,oci8,sqlserver,sqlite3,clickhouse,dm,kingbase,aci 和DBType对应,处理数据库有多个驱动
//		DriverName: GetDriverName(),
//		//数据库类型(方言判断依据):mysql,postgresql,oracle,mssql,sqlite,clickhouse,dm,kingbase,shentong 和 DriverName 对应,处理数据库有多个驱动
//		Dialect: GetDialect(),
//	}
//
//	return dbDaoConfig
//}
