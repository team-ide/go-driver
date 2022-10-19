module oscarOrmTest

go 1.14

require (
	github.com/stretchr/testify v1.4.0
)

require (
	github.com/davecgh/go-spew v1.1.0 // indirect
	github.com/emirpasic/gods v1.12.0 // indirect
	github.com/go-logfmt/logfmt v0.5.0 // indirect
	github.com/godror/godror v0.20.0 // indirect
	github.com/jinzhu/inflection v1.0.0 // indirect
	github.com/jinzhu/now v1.1.1 // indirect
	github.com/pmezard/go-difflib v1.0.0 // indirect
	github.com/thoas/go-funk v0.7.0 // indirect
	golang.org/x/xerrors v0.0.0-20191204190536-9bdfabe68543 // indirect
	gopkg.in/yaml.v2 v2.2.2 // indirect
)

require (
	go-aci v0.0.0 // indirect
	gorm.io/gorm v1.20.1
	oscar v0.0.0
)

replace (
	go-aci => ./go-aci
	oscar => ./oscar
)
