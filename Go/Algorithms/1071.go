package main

import "strings"

func gcdOfStrings(str1 string, str2 string) string {
	l, s := str1, str2
	if len(l) < len(s) {
		s, l = l, s
	}

	for ; len(s) != 0 && strings.HasPrefix(l, s); l, s = s, l {
		for ; strings.HasPrefix(l, s); l = l[len(s):] {
		}
	}
	if len(s) == 0 {
		return l
	}
	return ""
}
