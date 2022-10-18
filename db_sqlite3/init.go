package db_sqlite3

import (
	"fmt"
	"gitee.com/chunanyong/zorm"
	_ "github.com/mattn/go-sqlite3"
)

func NewDataSourceConfig(databasePath string) zorm.DataSourceConfig {
	connStr := fmt.Sprintf("%s", databasePath)
	dbDaoConfig := zorm.DataSourceConfig{
		//DSN 数据库的连接字符串
		DSN: connStr,
		//数据库驱动名称:mysql,postgres,oci8,sqlserver,sqlite3,clickhouse,dm,kingbase,aci 和DBType对应,处理数据库有多个驱动
		DriverName: "sqlite3",
		//数据库类型(方言判断依据):mysql,postgresql,oracle,mssql,sqlite,clickhouse,dm,kingbase,shentong 和 DriverName 对应,处理数据库有多个驱动
		Dialect: "sqlite",
	}

	return dbDaoConfig
}
