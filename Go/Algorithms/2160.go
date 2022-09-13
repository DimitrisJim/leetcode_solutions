package main

import "sort"

func minimumSum(num int) int {
	nums := make([]int, 4, 4)
	d := 1000

	for i := 0; i < 4; i++ {
		nums[i] = num / d
		num %= d
		d /= 10
	}

	sort.Ints(nums)
	return (nums[0]*10 + nums[2]) + (nums[1]*10 + nums[3])
}
