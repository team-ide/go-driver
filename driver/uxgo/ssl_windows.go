// +build windows

package uxgo

// sslKeyPermissions checks the permissions on user-supplied ssl key files.
// The key file should have very little access.
//
// libux does not check key file permissions on Windows.
func sslKeyPermissions(string) error { return nil }
