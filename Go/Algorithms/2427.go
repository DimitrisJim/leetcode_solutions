package main

func commonFactors(a int, b int) int {
	if a == 1 || b == 1 {
		return 1
	}
	fractions := 1
	max, min := a, b
	if max < min {
		max, min = min, max
	}
	if max%min == 0 {
		fractions += 1
	}

	for i := 2; i < (min/2)+1; i++ {
		if max%i == 0 && min%i == 0 {
			fractions += 1
		}
	}
	return fractions
}
