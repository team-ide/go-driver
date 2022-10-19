// +build windows

package gokb

// sslKeyPermissions checks the permissions on user-supplied ssl key files.
// The key file should have very little access.
//
// libkci does not check key file permissions on Windows.
func sslKeyPermissions(string) error { return nil }
