package main

func checkString(s string) bool {
	seen := false
	for _, ch := range s {
		if ch == 'b' {
			seen = true
		}
		if ch == 'a' && seen {
			return false
		}
	}
	return true
}
