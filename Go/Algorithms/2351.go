package main

func repeatedCharacter(s string) byte {
	seen := make(map[rune]struct{})
	for _, ch := range s {
		if _, ok := seen[ch]; ok {
			return byte(ch)
		}
		seen[ch] = struct{}{}
	}
	return ' '
}
