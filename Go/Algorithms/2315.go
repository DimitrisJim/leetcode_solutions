package main

func countAsterisks(s string) int {
	count, flag := 0, false

	for _, ch := range s {
		if ch == '|' {
			flag = !flag
			continue
		}
		if ch == '*' && !flag {
			count++
		}
	}
	return count
}
