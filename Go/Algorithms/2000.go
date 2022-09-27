package main

import "strings"

func reversePrefix(word string, ch byte) string {
	pos := strings.IndexByte(word, ch)
	if pos == -1 {
		return word
	}

	res := make([]byte, pos+1)
	for i := 0; i <= pos; i++ {
		res[pos-i] = word[i]
	}
	for i := pos + 1; i < len(word); i++ {
		res = append(res, word[i])
	}

	return string(res)
}
