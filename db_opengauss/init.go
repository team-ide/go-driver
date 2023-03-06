package db_opengauss

import (
	"database/sql"
	"fmt"
	_ "gitee.com/opengauss/openGauss-connector-go-pq"
)

func GetDriverName() string {
	return "opengauss"
}

func GetDialect() string {
	return "opengauss"
}

func GetDSN(user string, password string, host string, port int, database string) string {
	dsn := fmt.Sprintf("opengauss://%s:%s@%s:%d/%s?sslmode=disable", user, password, host, port, database)
	return dsn
}

func Open(dsn string) (db *sql.DB, err error) {
	db, err = sql.Open(GetDriverName(), dsn)
	if err != nil {
		return
	}
	return
}
