package main

import "sort"

func answerQueries(nums []int, queries []int) []int {
	sort.Ints(nums)
	sumnums := 0

	for i := 0; i < len(nums); i++ {
		nums[i] += sumnums
		sumnums = nums[i]
	}

	res := make([]int, len(queries))
	for i := 0; i < len(queries); i++ {
		res[i] = sort.Search(len(nums), func(idx int) bool { return nums[idx] > queries[i] })
	}
	return res
}
