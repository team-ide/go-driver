package db_gbase

import (
	"database/sql"
	_ "github.com/team-ide/go-driver/driver/odbc"
)

func GetDriverName() string {
	return "odbc"
}

func GetDialect() string {
	return "gbase"
}

func Open(dsn string) (db *sql.DB, err error) {
	db, err = sql.Open(GetDriverName(), dsn)
	if err != nil {
		return
	}
	return
}
