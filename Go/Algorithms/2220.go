package main

func minBitFlips(start int, goal int) int {
	count, b, s := 0, start, goal
	if goal > start {
		b, s = s, b
	}

	for s > 0 {
		if s&1 != b&1 {
			count++
		}
		s >>= 1
		b >>= 1
	}
	for b > 0 {
		if b&1 == 1 {
			count++
		}
		b >>= 1
	}
	return count
}
