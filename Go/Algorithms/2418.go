package main

import "sort"

type Person struct {
	Name   string
	Height int
}

func sortPeople(names []string, heights []int) []string {
	people := make([]Person, len(heights))
	for i := 0; i < len(heights); i += 1 {
		people[i].Name = names[i]
		people[i].Height = heights[i]
	}

	sort.Slice(people, func(i, j int) bool {
		return people[i].Height > people[j].Height
	})
	for i := 0; i < len(heights); i += 1 {
		names[i] = people[i].Name
	}

	return names
}
