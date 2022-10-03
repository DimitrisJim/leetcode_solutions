package main

func findGCD(nums []int) int {
	min, max := 1001, 0
	for _, num := range nums {
		if num > max {
			max = num
		}
		if num < min {
			min = num
		}
	}
	// euclidean.
	for ; min != 0; min, max = max%min, min {
	}
	return max
}
