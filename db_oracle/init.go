package db_oracle

import (
	"fmt"
	"gitee.com/chunanyong/zorm"
	//_ "github.com/mattn/go-oci8"
	_ "github.com/godror/godror"
)

/*

如出现异常：ORA-00000: DPI-1047: Cannot locate a 64-bit Oracle Client library: "The specified module could not be found". See https://oracle.github.io/odpi/doc/installation.html#windows for help

有以下解决方案：
方案一：
1、安装oracle 64位客户端
2、配置环境path，将客户端的目录，比如 c:\oracle\product\11.2.0\client_1\bin 配置到path中
3、配置环境变量ORACLE_HOME目录设置为如 c:\oracle\product\11.2.0\client_1 后，问题解决。

方案二：
1、下载轻量级的Oracle客户端： 比如 instantclient-basic-windows.x64-11.2.0.4.0.zip
2、配置环境变量path：将客户端的目录，比如 c:\oracle\instantclient_11_2 添加到 path
3、配置环境变量ORACL_HOME： 将客户端的上一级目录 ，比如 c:\oracle 设置为ORACLE_HOME的值

linux方案：
1、下载轻量级的oracle客户端并解压安装
2、配置环境变量LD_LIBRARY_PATH=[oracle客户端安装目录]:$LD_LIBRARY_PATH ，NLS_LANG=[oracle数据库NLS_LANGUAGE_NLS_TERRITORY.NLS_CHARACTERSET] ,并添加到 ~/.bash_profile 中
3、重新登录系统 或 source ~/.bash_profile 使环境变量生效
*/

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
