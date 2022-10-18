package db_kingbase

import (
	"fmt"
	"gitee.com/chunanyong/zorm"
	_ "github.com/lib/pq"
	//_ "kingbase.com/gokb"
)

func NewDataSourceConfig(user string, password string, host string, port int, database string) zorm.DataSourceConfig {
	connStr := fmt.Sprintf("user='%s' password='%s' host=%s port=%d dbname=%s sslmode=disable", user, password, host, port, database)
	//connStr := fmt.Sprintf("kingbase://%s:%s@%s:%d/%s?sslmode=disable", user, password, host, port, database)

	dbDaoConfig := zorm.DataSourceConfig{
		//DSN 数据库的连接字符串
		DSN: connStr,
		//数据库驱动名称:mysql,postgres,oci8,sqlserver,sqlite3,clickhouse,dm,kingbase,aci 和DBType对应,处理数据库有多个驱动
		DriverName: "postgres",
		//数据库类型(方言判断依据):mysql,postgresql,oracle,mssql,sqlite,clickhouse,dm,kingbase,shentong 和 DriverName 对应,处理数据库有多个驱动
		Dialect: "kingbase",
	}

	return dbDaoConfig
}
