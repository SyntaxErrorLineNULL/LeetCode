package problem2244

func minimumRounds(tasks []int) int {
	res := map[int]int{}
	complete := 0

	for _, index := range tasks {
		res[index]++
	}

	for _, count := range res {
		if count < 2 {
			return -1
		}

		complete += count / 3

		if count%3 > 0 {
			complete++
		}
	}

	return complete
}
