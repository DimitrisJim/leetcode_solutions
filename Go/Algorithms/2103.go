package main

func countPoints(rings string) int {
	RED, BLUE, GREEN := 1, 2, 4
	rods := make([]int, 10)

	for i := 1; i < len(rings); i += 2 {
		color, rod := rings[i-1], int(rings[i]-'0')
		if color == 'R' {
			rods[rod] |= RED
		} else if color == 'G' {
			rods[rod] |= GREEN
		} else {
			rods[rod] |= BLUE
		}
	}

	count := 0
	for _, i := range rods {
		if i == (RED | BLUE | GREEN) {
			count++
		}
	}
	return count
}
