package main

func findFinalValue(nums []int, original int) int {
	s := make(map[int]bool)
	for _, el := range nums {
		s[el] = true
	}
	// ugh
	for _, ok := s[original]; ok; _, ok = s[original] {
		original *= 2
	}
	return original
}
