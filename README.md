# go-driver
Go数据库驱动

* [Mysql](#Mysql)
* [Sqlite3](#Sqlite3)
* [达梦](#达梦)
* [金仓](#金仓)
* [Oracle](#Oracle)

## Mysql

* Docker 运行MySql

```shell
# 下载镜像
docker pull mysql:5.7
#运行一个容器
docker run -itd --name mysql-3306 -m 1024m -p 3306:3306 -e MYSQL_ROOT_PASSWORD=123456 mysql:5.7
#停止容器
docker stop mysql-3306
#删除容器
docker rm mysql-3306
```

* 程序调用

```go
package go_driver

import (
	"context"
	"fmt"
	"gitee.com/chunanyong/zorm"
	"github.com/team-ide/go-driver/db_mysql"
	"testing"
)

func TestMysql(t *testing.T) {
	dbConfig := db_mysql.NewDataSourceConfig("root", "123456", "127.0.0.1", 3306, "")
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
```

## Sqlite3

* 程序调用

```go
package go_driver

import (
	"context"
	"fmt"
	"gitee.com/chunanyong/zorm"
	"github.com/team-ide/go-driver/db_sqlite3"
	"testing"
)

func TestSqlite3(t *testing.T) {
	dbConfig := db_sqlite3.NewDataSourceConfig("test-sqlite3")
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
```

## 达梦

* Docker 运行达梦数据库

```shell
# 下载镜像
docker pull teamide/dm:v201106
#运行一个容器
docker run -itd --name dm-5236 -p 5236:5236 teamide/dm:v201106
#停止容器
docker stop dm-5236
#删除容器
docker rm dm-5236

# 端口: 5236
# 用户名: SYSDBA
# 密码: SYSDBA
```

* 程序调用

```go
package go_driver

import (
	"context"
	"fmt"
	"gitee.com/chunanyong/zorm"
	"github.com/team-ide/go-driver/db_dm"
	"testing"
)

func TestDm(t *testing.T) {
	dbConfig := db_dm.NewDataSourceConfig("SYSDBA", "SYSDBA", "127.0.0.1", 5236)
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
```

## 金仓

* Docker 运行金仓数据库

```shell
# 下载镜像
docker pull teamide/kingbase:v8r3
#运行一个容器
docker run -itd --name kingbase-54321 -p 54321:54321 -e SYSTEM_USER=SYSTEM -e SYSTEM_PWD=123456 teamide/kingbase:v8r3
#停止容器
docker stop kingbase-54321
#删除容器
docker rm kingbase-54321

# 端口: 54321
# 用户名: SYSTEM
# 密码: 123456
# 默认数据库: TEST
```

* 程序调用

```go
package go_driver

import (
	"context"
	"fmt"
	"gitee.com/chunanyong/zorm"
	"github.com/team-ide/go-driver/db_kingbase_v8r6"
	"testing"
)

func TestKingBase(t *testing.T) {
	//dbConfig := db_kingbase_v8r3.NewDataSourceConfig("SYSTEM", "123456", "127.0.0.1", 54321, "TEST")
	dbConfig := db_kingbase_v8r6.NewDataSourceConfig("SYSTEM", "123456", "127.0.0.1", 54321, "TEST")
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
```


## 神通

* Docker 运行神通数据库

```shell
# 下载镜像
docker pull teamide/shentong:7.0.8
#运行一个容器
docker run -itd --name shentong-2003 -p 2003:2003 teamide/shentong:7.0.8
#停止容器
docker stop shentong-2003
#删除容器
docker rm shentong-2003

# 端口: 2003
# 用户名: sysdba
# 密码: szoscar55
# 默认数据库: OSRDB
```

* 环境配置

**window 环境配置**
```shell
# 设置环境变量
PKG_CONFIG_PATH="C:\Code\go-driver\driver\shentong\go_aci-1.0.8.noarch.publish\drivers\go-aci"
# 将go-driver/driver/shentong/aci-2.0.47.win64.publish/bin/aci.dll 复制 到 C:/Windows/System32 下
```

**linux 环境配置**
```shell
# 设置环境变量
export PKG_CONFIG_PATH = $PKG_CONFIG_PATH:/data/code/go-driver/driver/shentong/go_aci-1.0.8.noarch.publish/drivers/go-aci
# 将driver/shentong/aci-2.0.47.linux64.publish/bin/libaci.so 复制 到 /usr/lib64/ 下
```


* 程序调用

```go
package go_driver

import (
	"context"
	"fmt"
	"gitee.com/chunanyong/zorm"
	"github.com/team-ide/go-driver/db_shentong"
	"testing"
)

func TestShenTong(t *testing.T) {
	dbConfig := db_shentong.NewDataSourceConfig("SYSDBA", "szoscar55", "127.0.0.1", 2003, "OSRDB")
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
```

## Oracle

* Docker 运行Oracle数据库

```shell
# 下载镜像
docker pull teamide/oracle-xe-11g:1.0
#运行一个容器
docker run -itd --name oracle-1521 -p 1521:1521 teamide/oracle-xe-11g:1.0
#停止容器
docker stop oracle-1521
#删除容器
docker rm oracle-1521

# 端口: 1521
# 用户名: root
# 密码: 123456
# SID: xe
```

* 环境配置

* 如出现异常：ORA-00000: DPI-1047: Cannot locate a 64-bit Oracle Client library: "The specified module could not be found". See https://oracle.github.io/odpi/doc/installation.html#windows for help

**window 环境配置**
* 方案一：
  1. 安装oracle 64位客户端
  2. 配置环境path，将客户端的目录，比如 c:\oracle\product\11.2.0\client_1\bin 配置到path中
  3. 配置环境变量ORACLE_HOME目录设置为如 c:\oracle\product\11.2.0\client_1 后，问题解决。
* 方案二：
  1. 下载轻量级的Oracle客户端： 比如 instantclient-basic-windows.x64-11.2.0.4.0.zip
  2. 配置环境变量path：将客户端的目录，比如 c:\oracle\instantclient_11_2 添加到 path
  3. 配置环境变量ORACL_HOME： 将客户端的上一级目录 ，比如 c:\oracle 设置为ORACLE_HOME的值


**linux 环境配置**
* 方案一：
  1. 下载轻量级的oracle客户端并解压安装
  2. 配置环境变量LD_LIBRARY_PATH=[oracle客户端安装目录]:$LD_LIBRARY_PATH ，NLS_LANG=[oracle数据库NLS_LANGUAGE_NLS_TERRITORY.NLS_CHARACTERSET] ,并添加到 ~/.bash_profile 中
  3. 重新登录系统 或 source ~/.bash_profile 使环境变量生效


* 程序调用

```go
package go_driver

import (
	"context"
	"fmt"
	"gitee.com/chunanyong/zorm"
	"github.com/team-ide/go-driver/db_oracle"
	"testing"
)

func TestOracle(t *testing.T) {
	dbConfig := db_oracle.NewDataSourceConfig("root", "123456", "127.0.0.1", 1521, "xe")
	sql := `select 2 from dual`
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
```