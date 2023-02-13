package db_gbase

import (
	"database/sql"
	"fmt"
	_ "github.com/team-ide/go-driver/driver/odbc"
)

func GetDriverName() string {
	return "odbc"
}

func GetDialect() string {
	return "gbase"
}

func GetDSN(odbcName string, user string, password string, databaseName string) string {
	dsn := fmt.Sprintf("DSN=%s;UID=%s;PWD=%s;NEWCODESET=UTF8,zh_cn.UTF8,57372;DB_LOCALE=zh_cn.57372;DELIMIDENT=Y;", odbcName, user, password)
	if databaseName != "" {
		dsn += fmt.Sprintf("DATABASE=%s;", databaseName)
	}
	//dsn += `host=127.0.0.1`
	//dsn += "service=9088;"
	return dsn
}

func Open(dsn string) (db *sql.DB, err error) {
	db, err = sql.Open(GetDriverName(), dsn)
	if err != nil {
		return
	}
	return
}
