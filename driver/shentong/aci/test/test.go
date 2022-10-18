package main

import (
	"database/sql"
	"fmt"
	"strings"
	_ "go-aci"
	"log"
	"os"
)

func main() {
	if len(os.Args) != 2 {
		log.Fatalln(os.Args[0] + " user/password@host:port/sid")
	}

	db, err := sql.Open("aci", os.Args[1])
	if err != nil {
		log.Fatalln(err)
	}
	defer db.Close()

	insertsql := "insert into test values(:1,:2)"
	stmt, err := db.Prepare(insertsql)
	stmt.Exec(1,6666)
	//stmt.Exec(2,bytes.Repeat([]byte("abcdefghijklmnopqrstuvwxyz"), 200))
	stmt.Exec(2,strings.Repeat("abcdefghijklmnopqrstuvwxyz",2))
	//stmt.Exec()

	rows, err := db.Query("select b from test")
	if err != nil {
		log.Fatalln(err)
	}
	defer rows.Close()

	for rows.Next() {
		var data string
		rows.Scan(&data)
		fmt.Println(data)
	}
	if err = rows.Err(); err != nil {
		log.Fatalln(err)
	}
}