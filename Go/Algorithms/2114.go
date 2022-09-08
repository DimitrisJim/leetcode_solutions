package main

import "strings"

func mostWordsFound(sentences []string) int {
	max := 0
	for _, sent := range sentences {
		tempmax := len(strings.Split(sent, " "))
		if tempmax >= max {
			max = tempmax
		}
	}
	return max
}
