package aci

// #cgo CFLAGS: -Iinclude
// #cgo arm64 LDFLAGS: -Llib/arm64  -laci
// #cgo loong64 LDFLAGS: -Llib/loongarch64  -laci
// #cgo mips64 LDFLAGS: -Llib/loongson64  -laci
// #cgo mips64le LDFLAGS: -Llib/loongson64  -laci
// #cgo amd64 && linux LDFLAGS: -Llib/linux64  -laci
// #cgo amd64 && windows LDFLAGS: -Llib/win64  -laci
// #cgo amd64 && macos LDFLAGS: -Llib/mac  -laci
// #include "aci.go.h"
import "C"
