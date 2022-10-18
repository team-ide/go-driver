package db_oracle

import (
	"fmt"
	"gitee.com/chunanyong/zorm"
	//_ "github.com/mattn/go-oci8"
	_ "github.com/godror/godror"
)

func NewDataSourceConfig(user string, password string, host string, port int, sid string) zorm.DataSourceConfig {
	//connStr := fmt.Sprintf("%s/%s@%s:%d/%s", user, password, host, port, sid)
	connStr := fmt.Sprintf(`user="%s" password="%s" connectString="%s:%d/%s"`, user, password, host, port, sid)
	dbDaoConfig := zorm.DataSourceConfig{
		//DSN 数据库的连接字符串
		DSN: connStr,
		//数据库驱动名称:mysql,postgres,oci8,sqlserver,sqlite3,clickhouse,dm,kingbase,aci 和DBType对应,处理数据库有多个驱动
		DriverName: "godror",
		//数据库类型(方言判断依据):mysql,postgresql,oracle,mssql,sqlite,clickhouse,dm,kingbase,shentong 和 DriverName 对应,处理数据库有多个驱动
		Dialect: "oracle",
	}

	return dbDaoConfig
}
