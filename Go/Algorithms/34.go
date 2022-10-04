package main

import "sort"

func searchRange(nums []int, target int) []int {
	low := sort.Search(len(nums), func(i int) bool { return nums[i] >= target })
	high := sort.Search(len(nums), func(i int) bool { return nums[i] > (target) })
	if low == high {
		return []int{-1, -1}
	} else {
		return []int{low, high - 1}
	}
}
