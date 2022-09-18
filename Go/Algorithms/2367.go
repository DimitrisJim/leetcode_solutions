package main

func arithmeticTriplets(nums []int, diff int) int {
	pair, end := 0, len(nums)

	for i := 0; i < end-2; i++ {
		for j := i + 1; j < end-1; j++ {
			numdiff := nums[j] - nums[i]
			if numdiff > diff {
				break
			}
			if numdiff == diff {
				for k := j + 1; k < end; k++ {
					numdiff = nums[k] - nums[j]
					if numdiff > diff {
						break
					}
					if numdiff == diff {
						pair++
					}
				}
			}
		}
	}
	return pair
}
