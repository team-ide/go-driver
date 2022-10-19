# go-driver
Go数据库驱动

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
docker pull xzxiaoshan/dm8:v201106
#运行一个容器
docker run -itd --name dm-5236 -p 5236:5236 xzxiaoshan/dm8:v201106 /startDm.sh
#停止容器
docker stop dm-5236
#删除容器
docker rm dm-5236

# 端口: 54321
# 用户名: SYSDBA
# 密码: SYSDBA
# 默认数据库: TEST
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
docker pull ghcr.io/renfei/kingbase:v8r3
#运行一个容器
docker run -itd --name kingbase-54321 -p 54321:54321 -e SYSTEM_PWD=123456 ghcr.io/renfei/kingbase:v8r3

# 进入容器
docker exec -it kingbase-54321 bash

# 创建license.dat
vi /opt/kingbase/Server/bin/license.dat
# 输入内容
`
-------------------BEGIN KINGASE.LICENSE.3.0 PRIVATE KEY-------------------
C2jEV4qxkPiL106gQ3qln52jK4nZLfFmcNhvYAlfQaMEUEkU5XB5ZxA5CCMzc4CjsMFybE
vye7qLXGRoXTgSEL7I/zqAJH4Pgjtz103k73vcjQQ5UTtnIb3cW7eblGjW7iPk+A3sfw4P
ATodyPr5mkmLkxc3q+NAYCroVi8x8Z8vga73Wq5SD7g+YZd6uoTxmkOxWPRytYpeHcwDxY
uS1RVBvaN+34D0Oft0nwRB+mLn8yYwmtwMeWA161C2LjPx8kcJF5jF/Sp8CwW7+cs0Lk5/
7L2nXyfC1HcdhEoTCiieDylidhEnnC6gpiOEgZzrQWzUxLcLRxIxzzfxu9y0DYP+GLqtcx
dAB2EGYII+MHaAUo/R1J8OqcfIOKujwd+QUyRa3SEhft9iQX2zBSxwutK66brRgpxLJgPU
ZZQQlWOVdkPFLfSJLPBbPqGG5w/5od5P8u7VAzsCZnhc8Fx0M5V2Q8Ut9Iks8Fs+oYbnD/
lX+Hruem+QpMylUDPpzmOdDnroa9hrbhIwZc7T47ZBwNGZaFZxAcLW7QihLnyAr3JiXfLo
AwiXiQmPa0w/D9k/t+3xZqprGuIqAdYGMw03D4m/cSSpTQT92/TlpyiFkm16LF1AIZ39S5
OajzAuHatbLkdxQe202xd2RqR/HhM0knKcQnpC00PQu8skS3hU88vtnstWip/+vrutmbKq
UeGL+jgnaS0A08EmvVXfNON4jfLjDE/9NHcswJemhsFj87t7kTmghh/Uf5k1U7Odp+jloX
QR1P4Rda3yDktjyI//d1xb+dmOL7bWVAXfZC/gwZWoXPkhJE7jfgd5RhGVdpamJmgmuyUW
XxqHKqMGPVlnw8iZxcUkvfY8kGe6rFdiLNVNEP5OYTAR7Ouwam/1kKi3MK4hBsIeaCDuGS
UfH54oGfi583ORSOayIpt1DEysPgh6mt0UOwbgqe3yuzGuVEkDQi9cb0djzbOTX8edyUYx
DsJc8BetZ3fR30MYa3+1d213fRZE+bOq5K9NLZkzLjRYpXpsQqSzwD5OZtlRfZEkT2kA8s
IpZU1qGNi5R33ynt3hIuAbBq0YumQymbVAOkx2w2De3NcCfkVMvag9Bdynevi583ORSOay
Ipt1DEysPggKfcfpjEzdoaeGQ2sTmyo+8PEKCJRS/6lM+yFdPLiiu8GVlr8a8WAbyjvr3N
7Kfgf9NAJdfcw3IIy8oTnm69qEH81vrpgqblq/HR8fjHXbgEuIYd5HFRHEGQohcRCdakf4
ufNzkUjmsiKbdQxMrD4Ijo0BMb5iu3DTygNp/EwsgkX27b4819cssGFOlbOy3CUNYlrODq
/afZMQKvK9ZowdnviaN1EFtldhRKi8btPr9ugFMVynNwk0sDVO+LJ3PTW9OJPO7h1GwBKw
/5iFfodkrUSYipdHFB90h63XSUzxGtW06pBRoxzhY3+tBG+4br4dWD1dWqKCp3UIApQggN
QuIu0a9GIcMfvIQnGoasGwRM0JiCDEwgrkjV8qo2lQt7+KESwmi9au8rpDwAT88ovS
----------------------------------MD5SUM-----------------------------------
bdc044e2ad46b47b63266d20b1a52c69
-------------------END KINGASE.LICENSE.3.0 PRIVATE KEY---------------------
License序列号 --- 启用 --- 15FD7A48-77DE-11EB-B12A-000C29CBE49F
生产日期 --- 启用 --- 2021-02-26
产品名称 --- 启用 --- KingbaseES V8
细分版本模板名 --- 启用 --- SALES-开发版 V8R3
产品版本号 --- 启用 --- V008R003C
浮动基准日期 ------ 禁用
有效期间 --- 启用 --- 0
用户名称 --- 启用 --- 试用
项目名称 --- 启用 --- 试用
CPU检查 --- 启用 --- 0
MAC地址 --- 启用 --- 00:00:00:00:00:00
最大连接数 --- 启用 --- 10
数据同步 --- 启用 --- 0
物理同步 --- 启用 --- 0
增量备份恢复 --- 启用 --- 0
集群对网络故障的容错 --- 启用 --- 0
集群配置工具 --- 启用 --- 0
读写分离模块 --- 启用 --- 0
保密通讯协议 --- 启用 --- 0
审计 --- 启用 --- 0
三权分立 --- 启用 --- 0
密码复杂度 --- 启用 --- 0
用户锁定 --- 启用 --- 0
运行状态分析 --- 启用 --- 0
滚动升级 --- 启用 --- 0
恢复到指定时间点 --- 启用 --- 0
快速加载 --- 启用 --- 0
日志压缩 --- 启用 --- 0
全文检索 --- 启用 --- 0
健康检查 --- 启用 --- 0
并行查询 --- 启用 --- 0
并行备份还原 --- 启用 --- 0
日志解析 --- 启用 --- 0
异构数据源 --- 启用 --- 0
透明加密 --- 启用 --- 0
强制访问控制 --- 启用 --- 0
`
# 修改 kingbase.conf
vi /opt/kingbase/data/kingbase.conf

`
max_connections = 10                    # (change requires restart)
superuser_reserved_connections = 9      # (change requires restart)
super_manager_reserved_connections = 8  # (change requires restart)
`

# 退出容器
exit
# 重启容器
docker restart kingbase-54321

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

func TestKinBase(t *testing.T) {
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