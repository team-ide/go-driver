@echo on

cd %~dp0
cd ../

REM go build -ldflags "-s -w"

go env -w CGO_ENABLED=1
go env -w GOOS=windows
go env -w GOARCH=amd64

go build -gcflags="all=-N -l" -ldflags "-s -w -extldflags -static" -o ./out/windows-amd64-driver.exe