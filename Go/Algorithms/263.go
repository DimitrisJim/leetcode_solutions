package main

func isUgly(n int) bool {
	if n == 0 {
		return false
	}
	primes, i := []int{2, 3, 5}, 0

	for n != 1 {
		prime := primes[i]
		if n%prime == 0 {
			n /= prime
		} else {
			i += 1
		}
		if i >= 3 {
			return false
		}
	}
	return true
}
