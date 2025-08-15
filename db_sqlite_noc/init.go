package db_sqlite_noc

import (
	"database/sql"
	_ "modernc.org/sqlite"
)

func GetDriverName() string {
	return "sqlite"
}

func GetDialect() string {
	return "sqlite"
}

func GetDSN(databasePath string) string {
	dsn := databasePath
	return dsn
}

func Open(dsn string) (db *sql.DB, err error) {
	db, err = sql.Open(GetDriverName(), dsn)
	if err != nil {
		return
	}
	return
}
