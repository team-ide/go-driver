# go-driver
Go数据库驱动

* [Mysql](#Mysql)
* [达梦](#达梦)
* [金仓](#金仓)
* [神通](#神通)
* [GBase](#GBase)
* [Sqlite3](#Sqlite3)
* [Oracle](#Oracle)
* [Postgresql](#Postgresql)
  
## 编译

* [参照 编译 说明](编译.md)

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
package main

import (
  "fmt"
  "github.com/team-ide/go-driver/db_mysql"
  "testing"
)

func TestMysql(t *testing.T) {

  dsn := db_mysql.GetDSN("root", "123456", "127.0.0.1", 3306, "")
  db, err := db_mysql.Open(dsn)
  if err != nil {
    panic(err)
  }
  sql := `select 2`
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

```

## Sqlite3

* 程序调用

```go
package main

import (
  "fmt"
  "github.com/team-ide/go-driver/db_sqlite3"
  "testing"
)

func TestSqlite3(t *testing.T) {

  dsn := db_sqlite3.GetDSN("test-sqlite3")
  db, err := db_sqlite3.Open(dsn)
  if err != nil {
    panic(err)
  }
  sql := `select 2`
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

```

## 达梦

* Docker 运行达梦数据库

```shell
# 下载镜像
docker pull teamide/dm8:v201106
#运行一个容器
docker run -itd --name dm-5236 -p 5236:5236 teamide/dm8:v201106
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
package main

import (
  "fmt"
  "github.com/team-ide/go-driver/db_dm"
  "testing"
)

func TestDm(t *testing.T) {
  dsn := db_dm.GetDSN("SYSDBA", "SYSDBA", "127.0.0.1", 5236)
  db, err := db_dm.Open(dsn)
  if err != nil {
    panic(err)
  }
  sql := `select 2`
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
package main

import (
  "fmt"
  "github.com/team-ide/go-driver/db_kingbase_v8r6"
  "testing"
)

func TestKingBase(t *testing.T) {
  dsn := db_kingbase_v8r6.GetDSN("SYSTEM", "123456", "127.0.0.1", 54321, "TEST")
  db, err := db_kingbase_v8r6.Open(dsn)
  if err != nil {
    panic(err)
  }
  sql := `select 2`
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
# 配置 动态链接库
# 将go-driver/driver/shentong/go-aci/lib/win64/aci.dll 复制 到 C:/Windows/System32 下
# 或 将 aci.dll 放在程序目录
```

**linux 环境配置**
```shell
# 将go-driver/driver/shentong/go-aci/lib/linux64/libaci.so 复制 到 /usr/lib64/ 下
# 或 配置 动态链接库
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:go-driver/driver/shentong/go-aci/lib/linux64/
```


* 程序调用

```go
package main

import (
  "fmt"
  "github.com/team-ide/go-driver/db_shentong"
  "testing"
)

func TestShenTong(t *testing.T) {

  dsn := db_shentong.GetDSN("SYSDBA", "szoscar55", "127.0.0.1", 2003, "OSRDB")
  db, err := db_shentong.Open(dsn)
  if err != nil {
    panic(err)
  }
  sql := `select 2`
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
package main

import (
  "fmt"
  "github.com/team-ide/go-driver/db_oracle"
  "testing"
)

func TestOracle(t *testing.T) {

  dsn := db_oracle.GetDSN("root", "123456", "127.0.0.1", 1521, "xe")
  db, err := db_oracle.Open(dsn)
  if err != nil {
    panic(err)
  }
  sql := `select 2 from dual`
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

```




## Postgresql

* Docker 运行Postgresql数据库

```shell
# 下载镜像
docker pull postgres:11.14
#运行一个容器
docker run -itd --name postgres-5432 -p 5432:5432 -e POSTGRES_PASSWORD=123456 postgres:11.14
#停止容器
docker stop postgres-5432
#删除容器
docker rm postgres-5432

# 端口: 5432
# 用户名: postgres
# 密码: 123456
# 默认数据库: postgres
```

* 程序调用

```go
package main

import (
  "fmt"
  "github.com/team-ide/go-driver/db_postgresql"
  "testing"
)

func TestPostgresql(t *testing.T) {

  dsn := db_postgresql.GetDSN("postgres", "123456", "127.0.0.1", 5432, "postgres")
  db, err := db_postgresql.Open(dsn)
  if err != nil {
    panic(err)
  }
  sql := `select 2`
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

```




## GBase

* Docker 运行GBase数据库

```shell
# 下载镜像
docker pull teamide/gbase8s:3.3.0_2_amd64
#运行一个容器
docker run -itd --name gbase-9088 -p 9088:9088 teamide/gbase8s:3.3.0_2_amd64
#停止容器
docker stop gbase-9088
#删除容器
docker rm gbase-9088

# 端口: 9088
# 用户名: gbasedbt
# 密码: GBase123
# 默认数据库: OSRDB
```

* GBase 相关资源文档
  * https://gbasedbt.com/dl/
  * https://gbasedbt.com/dl/odbc/
  * https://gbasedbt.com/dl/Demo4GBase8s/

* window 配置 odbc

```shell

# 下载 https://gbasedbt.com/dl/odbc/GBase8s_3.0-Win64-ODBC-Driver.zip

# 解压
# 使用管理员权限运行00注册ODBC_管理员权限运行.cmd，注册ODBC驱动

# 打开window odbc配置，添加GBase驱动


```

* 程序调用

```go
package main

import (
  "fmt"
  "github.com/team-ide/go-driver/db_gbase"
  "testing"
)

func TestGBase(t *testing.T) {
  dsn := db_gbase.GetDSN("gbase", "gbasedbt", "GBase123", "")
  db, err := db_gbase.Open(dsn)
  if err != nil {
    panic(err)
  }
  sql := `select 2 from dual`
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


```