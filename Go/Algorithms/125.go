package main

import "strings"

func isLetter(c rune) bool {
	return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9')
}

func isPalindrome(s string) bool {
	var r strings.Builder
	for _, ch := range strings.ToUpper(s) {
		if isLetter(ch) {
			r.WriteRune(ch)
		}
	}
	s = r.String()
	start, end := 0, len(s)-1
	for ; start < end; start, end = start+1, end-1 {
		if s[start] != s[end] {
			return false
		}
	}
	return true
}
