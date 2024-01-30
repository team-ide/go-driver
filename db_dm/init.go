package db_dm

import (
	"database/sql"
	"fmt"
	_ "github.com/team-ide/go-driver/driver/dm"
)

func GetDriverName() string {
	return "dm"
}

func GetDialect() string {
	return "dm"
}

func GetDSN(user string, password string, host string, port int, schema string) string {
	dsn := fmt.Sprintf("dm://%s:%s@%s:%d?charset=utf8", user, password, host, port)
	if schema != "" {
		dsn += "&schema=" + schema
	}
	return dsn
}

func Open(dsn string) (db *sql.DB, err error) {
	db, err = sql.Open(GetDriverName(), dsn)
	if err != nil {
		return
	}
	return
}

//func NewDataSourceConfig(user string, password string, host string, port int) zorm.DataSourceConfig {
//	dsn := GetDSN(user, password, host, port)
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

//CustomDMText 实现CustomDriverValueConver接口,扩展自定义类型,例如 达梦数据库text类型,映射出来的是dm.DmClob类型,无法使用string类型直接接收
//type CustomDMText struct{}

//GetDriverValue 根据数据库列类型,实体类属性类型,Finder对象,返回driver.Value的实例
//如果无法获取到structFieldType,例如Map查询,会传入nil
//如果返回值为nil,接口扩展逻辑无效,使用原生的方式接收数据库字段值
//func (dmtext CustomDMText) GetDriverValue(columnType *sql.ColumnType, structFieldType *reflect.Type, finder *zorm.Finder) (driver.Value, error) {
//	return &dm.DmClob{}, nil
//}

//ConverDriverValue 数据库列类型,实体类属性类型,GetDriverValue返回的driver.Value的临时接收值,Finder对象
//如果无法获取到structFieldType,例如Map查询,会传入nil
//返回符合接收类型值的指针,指针,指针!!!!
//func (dmtext CustomDMText) ConverDriverValue(columnType *sql.ColumnType, structFieldType *reflect.Type, tempDriverValue driver.Value, finder *zorm.Finder) (interface{}, error) {
//	if tempDriverValue == nil {
//		str := ""
//		return &str, nil
//	}
//	//类型转换
//	dmClob, isok := tempDriverValue.(*dm.DmClob)
//	if !isok {
//		return tempDriverValue, errors.New("转换至*dm.DmClob类型失败")
//	}
//
//	//获取长度
//	dmlen, errLength := dmClob.GetLength()
//	if errLength != nil {
//		return dmClob, errLength
//	}
//
//	//int64转成int类型
//	strInt64 := strconv.FormatInt(dmlen, 10)
//	dmlenInt, errAtoi := strconv.Atoi(strInt64)
//	if errAtoi != nil {
//		return dmClob, errAtoi
//	}
//
//	//读取字符串
//	str, errReadString := dmClob.ReadString(1, dmlenInt)
//	if errReadString == io.EOF {
//		errReadString = nil
//	}
//	return &str, errReadString
//}
