module job-engine

go 1.18

replace go-aci => ./driver/shentong/aci

replace kingbase.com/gokb => ./driver/kingbase/gokb

replace github.com/alexbrainman/odbc => ./driver/odbc

require (
	gitee.com/chunanyong/dm v1.8.8
	gitee.com/chunanyong/zorm v1.6.1
	github.com/alexbrainman/odbc v0.0.0-00010101000000-000000000000
	github.com/go-sql-driver/mysql v1.6.0
	go-aci v0.0.0-00010101000000-000000000000
	kingbase.com/gokb v0.0.0-00010101000000-000000000000
)

require (
	github.com/golang/snappy v0.0.1 // indirect
	golang.org/x/sys v0.0.0-20190916202348-b4ddaad3f8a3 // indirect
	golang.org/x/text v0.3.2 // indirect
)
