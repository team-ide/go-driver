@echo on

cd %~dp0

go test -v -timeout 10m -count 1 -run ^Test password_test.go
