package aci

/*
#cgo CFLAGS: -Iinclude
#cgo LDFLAGS: -Llib -laci
#cgo arm64 LDFLAGS: -Llib/arm64  -laci
#cgo loong64 LDFLAGS: -Llib/loong64  -laci
#cgo mips64 LDFLAGS: -Llib/mips64  -laci
#cgo mips64le LDFLAGS: -Llib/mips64  -laci
#cgo sw64 LDFLAGS: -Llib/shenwei64  -laci
#cgo amd64 && linux LDFLAGS: -Llib/amd64  -laci
#cgo amd64 && windows LDFLAGS: -Llib/win64  -laci
#include "aci.go.h"
*/
import "C"
