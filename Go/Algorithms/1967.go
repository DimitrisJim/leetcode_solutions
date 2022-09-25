package main

import "strings"

func numOfStrings(patterns []string, word string) int {
	count := 0
	for _, pat := range patterns {
		if strings.Contains(word, pat) {
			count += 1
		}
	}
	return count
}
