package main

func isSameAfterReversals(num int) bool {
	if num == 0 {
		return true
	}
	return num%10 != 0
}
