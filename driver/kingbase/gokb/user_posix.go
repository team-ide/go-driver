// Package kb is a pure Go Kingbase driver for the database/sql package.

// +build aix darwin dragonfly freebsd linux nacl netbsd openbsd solaris rumprun

package gokb

import (
	"os"
	"os/user"
)

func userCurrent() (string, error) {
	u, err := user.Current()
	if err == nil {
		return u.Username, nil
	}

	name := os.Getenv("USER")
	if name != "" {
		return name, nil
	}

	return "", ErrCouldNotDetectUsername
}
