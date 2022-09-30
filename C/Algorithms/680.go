package main

func cmpdiff(s string, start, end int) (int, int, int) {
	for ; start < end; start, end = start+1, end-1 {
		if s[start] != s[end] {
			return start, end, 1
		}
	}
	return start, end, 0
}

func validPalindrome(s string) bool {
	start, end, diff := cmpdiff(s, 0, len(s)-1)
	if diff == 0 {
		return true
	}

	_, _, diff = cmpdiff(s, start+1, end)
	if diff == 0 {
		return true
	}
	_, _, diff = cmpdiff(s, start, end-1)
	if diff == 0 {
		return true
	}
	return false
}
