package aci

/*
#cgo CFLAGS: -Iinclude
#cgo LDFLAGS: -L./lib -laci
#cgo amd64 && windows LDFLAGS: -L./lib/win64  -laci
#include "aci.go.h"
*/
import "C"
