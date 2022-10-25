package main

func divideArray(nums []int) bool {
	s := make(map[int]bool)
	for _, num := range nums {
		if _, ok := s[num]; ok {
			delete(s, num)
		} else {
			s[num] = true
		}
	}
	return len(s) == 0
}
