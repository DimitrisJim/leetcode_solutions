package main

import "sort"

func minMovesToSeat(seats []int, students []int) int {
	sort.Ints(seats)
	sort.Ints(students)

	sum, length, diff := 0, len(seats), 0
	for i := 0; i < length; i++ {
		diff = seats[i] - students[i]
		if diff < 0 {
			diff = -diff
		}
		sum += diff
	}
	return sum
}
