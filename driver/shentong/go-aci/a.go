package aci

// #cgo CFLAGS: -Iinclude
// #cgo loong64 && linux LDFLAGS: -Llib/loongarch64  -laci
// #cgo mips64 && linux LDFLAGS: -Llib/loongson64  -laci
// #cgo mips64le && linux LDFLAGS: -Llib/loongson64  -laci
// #cgo amd64 && linux LDFLAGS: -Llib/linux64  -laci
// #cgo amd64 && windows LDFLAGS: -Llib/win64  -laci
// #include "aci.go.h"
import "C"
