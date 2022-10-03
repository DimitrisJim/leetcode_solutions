package main

import "sort"

func targetIndices(nums []int, target int) []int {
	sort.Ints(nums)
	result := []int{}
	for idx, num := range nums {
		if num == target {
			result = append(result, idx)
		}
	}
	return result
}
