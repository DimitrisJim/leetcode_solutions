package main

import "strings"

func isPrefixString(s string, words []string) bool {
	for _, word := range words {
		if !strings.HasPrefix(s, word) {
			break
		}
		s = s[len(word):]
	}
	return s == ""
}
