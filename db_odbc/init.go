package db_odbc

import (
	"database/sql"
	"fmt"
	_ "github.com/team-ide/go-driver/driver/odbc"
)

func GetDriverName() string {
	return "odbc"
}

func GetDialect() string {
	return "odbc"
}

func GetDSN(odbcName string, user string, password string) string {
	dsn := fmt.Sprintf("DSN=%s;UID=%s;PWD=%s", odbcName, user, password)
	return dsn
}

func Open(dsn string) (db *sql.DB, err error) {
	db, err = sql.Open(GetDriverName(), dsn)
	if err != nil {
		return
	}
	return
}
