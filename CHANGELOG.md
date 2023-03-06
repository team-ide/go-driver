# 1.1.9

## Version 1.1.9（2023/3/6）

发布功能

1. 添加OpenGauss支持，驱动使用`gitee.com/opengauss/openGauss-connector-go-pq`

# 1.1.4

## Version 1.1.4 （2023/02/10）

发布功能

1. 添加GBase支持，驱动使用odbc

# 1.1.2

## Version 1.1.2 （2022/12/02）

发布功能

1. 升级 gitee.com/chunanyong/dm > v1.8.9
2. 升级 github.com/godror/godror > v0.35.1
3. 升级 github.com/mattn/go-sqlite3 > v1.14.16
4. 添加odbc

# 1.1.0

## Version 1.1.0 （2022/11/18）

发布功能

1. oracle使用godror驱动
2. oracle的Open方法，调用NewDriver、NewConnector，否则会使用godror的默认driver，导致无法关闭

# 1.0.8

## Version 1.0.8 （2022/10/27）

发布功能

1. mysql驱动支持，添加测试
2. 达梦驱动支持，添加测试
3. 金仓驱动支持，添加测试
   * 金仓数据库 bool 类型 修改为为返回 "0" 或 "1"
   * 金仓数据库驱动添加v8r3-kingbase、v8r6-kingbase
4. 神通驱动支持，添加测试
5. sqlite3驱动支持，添加测试
6. oracle驱动支持，添加测试
7. postgresql驱动支持，添加测试

**驱动包中添加Open方法，直接调用的sql.Open**

# 1.0.6

## Version 1.0.6 （2022/10/25）

发布功能

1. mysql驱动支持，添加测试
2. 达梦驱动支持，添加测试
3. 金仓驱动支持，添加测试
    * 金仓数据库 bool 类型 修改为为返回 "0" 或 "1"
    * 金仓数据库驱动添加v8r3-kingbase、v8r6-kingbase
4. 神通驱动支持，添加测试
5. sqlite3驱动支持，添加测试
6. oracle驱动支持，添加测试

# 0.0.1

## Version 0.0.1 （2022/10/18）

发布功能

1. 添加mysql、oracle、sqlite3、dm、kingbase、shentong驱动