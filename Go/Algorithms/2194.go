package main

import "strconv"

func cellsInRange(s string) []string {
	c1, c2, r1, r2 := int(s[0]), int(s[3]), int(s[1]-'0'), int(s[4]-'0')

	var res []string
	for c := c1; c <= c2; c++ {
		for r := r1; r <= r2; r++ {
			res = append(res, string(rune(c))+strconv.Itoa(r))
		}
	}

	return res
}
