package main

func countKDifference(nums []int, k int) int {
	counts := make(map[int]int)

	for _, i := range nums {
		counts[i]++
	}

	count := 0
	for _, i := range nums {
		a, b := i-k, i+k
		if a > 0 && a < 101 && counts[a] > 0 {
			count += counts[a]
		}
		if b < 101 && counts[b] > 0 {
			count += counts[b]
		}
		counts[i]--
	}

	return count
}
