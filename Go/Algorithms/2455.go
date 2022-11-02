package main

func averageValue(nums []int) int {
	sum, count := 0, 0
	for _, val := range nums {
		if val&1 == 0 && val%3 == 0 {
			sum += val
			count++
		}
	}
	if count == 0 {
		return 0
	}
	return int(sum / count)
}
