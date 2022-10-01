package main

import "strings"

func prefixCount(words []string, pref string) int {
	count := 0
	for _, word := range words {
		if strings.HasPrefix(word, pref) {
			count += 1
		}
	}
	return count
}
