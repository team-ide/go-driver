module github.com/team-ide/go-driver

go 1.18

replace go-aci => ./driver/shentong/aci

replace v8r3/kingbase.com/gokb => ./driver/kingbase/v8r3/kingbase.com/gokb

replace v8r6/kingbase.com/gokb => ./driver/kingbase/v8r6/kingbase.com/gokb

require (
	gitee.com/chunanyong/dm v1.8.8
	gitee.com/chunanyong/zorm v1.6.1
	github.com/go-sql-driver/mysql v1.6.0
	github.com/godror/godror v0.34.0
	github.com/mattn/go-sqlite3 v1.14.15
	go-aci v0.0.0-00010101000000-000000000000
	v8r3/kingbase.com/gokb v0.0.0-00010101000000-000000000000
	v8r6/kingbase.com/gokb v0.0.0-00010101000000-000000000000
)

require (
	github.com/go-logfmt/logfmt v0.5.1 // indirect
	github.com/go-logr/logr v1.2.3 // indirect
	github.com/godror/knownpb v0.1.0 // indirect
	github.com/golang/snappy v0.0.1 // indirect
	golang.org/x/text v0.3.2 // indirect
	google.golang.org/protobuf v1.27.1 // indirect
)
