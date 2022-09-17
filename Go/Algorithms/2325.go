package main

import "strings"

func decodeMessage(key string, message string) string {
	chars := make(map[rune]byte)
	ascii_lower := "abcdefghijklmnopqrstuvwxyz"

	for _, ch := range key {
		if _, ok := chars[ch]; !ok {
			if ch != ' ' {
				chars[ch] = ascii_lower[len(chars)]
			}
		}
	}
	chars[' '] = ' '

	var sb strings.Builder
	for _, ch := range message {
		sb.WriteByte(chars[ch])
	}

	return sb.String()
}
