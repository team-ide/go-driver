package db_sqlite3

import (
	"database/sql"
	_ "github.com/mattn/go-sqlite3"
)

func GetDriverName() string {
	return "sqlite3"
}

func GetDialect() string {
	return "sqlite"
}

func GetDSN(databasePath string) string {
	dsn := databasePath
	return dsn
}

func Open(dsn string) (db *sql.DB, err error) {
	db, err = sql.Open(GetDriverName(), dsn)
	if err != nil {
		return
	}
	return
}

//func NewDataSourceConfig(databasePath string) zorm.DataSourceConfig {
//	dsn := GetDSN(databasePath)
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
