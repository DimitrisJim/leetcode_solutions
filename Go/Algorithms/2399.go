package main

func checkDistances(s string, distance []int) bool {
	for i := 0; i < len(s)-1; i += 1 {
		pos := s[i] - 97

		// Mark distance if seen.
		dist := distance[pos] + 1
		if dist == -1 {
			continue
		} else {
			distance[pos] = -2
		}
		dist += i
		if dist < len(s) && s[dist] == s[i] {
			continue
		} else {
			return false
		}
	}
	return true
}
