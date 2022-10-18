module job-engine

go 1.18

replace go-aci => ./driver/shentong/aci

replace kingbase.com/gokb => ./driver/kingbase/gokb

require (
	gitee.com/chunanyong/dm v1.8.8
	gitee.com/chunanyong/zorm v1.6.1
	github.com/go-sql-driver/mysql v1.6.0
	github.com/mattn/go-oci8 v0.1.1
	github.com/mattn/go-sqlite3 v1.14.15
	go-aci v0.0.0-00010101000000-000000000000
	kingbase.com/gokb v0.0.0-00010101000000-000000000000
)

require (
	github.com/golang/snappy v0.0.1 // indirect
	golang.org/x/text v0.3.2 // indirect
)
