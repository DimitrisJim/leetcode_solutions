package main

import "unicode"

func areNumbersAscending(s string) bool {
	previous, next := 0, 0
	for start, end := 0, len(s); start < end; start += 1 {
		digit := 0
		for ; start < end && unicode.IsDigit(rune(s[start])); start += 1 {
			digit *= 10
			digit += int(s[start] - '0')
		}
		if digit > 0 {
			next = digit
			if next <= previous {
				return false
			}
			previous = next
		}
	}
	return true
}
