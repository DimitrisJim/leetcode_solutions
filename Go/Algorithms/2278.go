package main

func percentageLetter(s string, letter byte) int {
	count := 0
	for _, ch := range s {
		if byte(ch) == letter {
			count++
		}
	}
	return int(float64(count) / float64(len(s)) * 100)
}
