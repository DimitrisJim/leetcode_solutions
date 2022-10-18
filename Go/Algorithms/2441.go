package main

import "sort"

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func findMaxK(nums []int) int {
	sort.Slice(nums, func(i, j int) bool { return abs(nums[i]) > abs(nums[j]) })

	for i := 1; i < len(nums); i += 1 {
		if nums[i]+nums[i-1] == 0 {
			return abs(nums[i])
		}
	}
	return -1
}
