package aci

/*
#cgo CFLAGS: -Iinclude
#cgo LDFLAGS: -L./lib -laci  -ldl
#cgo amd64 && windows LDFLAGS: -L./lib/win64  -laci  -ldl
#include "aci.go.h"
*/
import "C"
