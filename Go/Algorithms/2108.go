package main

func firstPalindrome(words []string) string {
	for _, word := range words {
		start, end, found := 0, len(word)-1, true
		for ; start < end; start, end = start+1, end-1 {
			if word[start] != word[end] {
				found = false
				break
			}
		}
		if found {
			return word
		}
	}
	return ""
}
