package main

func smallestEvenMultiple(n int) int {
	if n&1 == 1 {
		return n << 1
	}
	return n
}
