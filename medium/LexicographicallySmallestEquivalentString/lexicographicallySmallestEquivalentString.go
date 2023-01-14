package problem1061

func smallestEquivalentString(s1 string, s2 string, baseStr string) string {
	graph := make(map[rune]map[rune]bool)
	for i, _ := range s1 {
		p := rune(s1[i])
		q := rune(s2[i])
		if _, ok := graph[p]; !ok {
			graph[p] = make(map[rune]bool)
		}
		if _, ok := graph[q]; !ok {
			graph[q] = make(map[rune]bool)
		}
		graph[p][q] = true
		graph[q][p] = true
	}

	answer := []rune{}
	for _, char := range baseStr {
		visited := make(map[rune]bool)
		answer = append(answer, dfs(char, &graph, &visited))
	}
	return string(answer)
}

func dfs(node rune, graph *map[rune]map[rune]bool, visited *map[rune]bool) rune {
	if _, ok := (*visited)[node]; ok {
		return node
	}

	(*visited)[node] = true
	letter := node

	for n, _ := range (*graph)[node] {
		letter = min(letter, dfs(n, graph, visited))
	}
	return letter
}

func min(a, b rune) rune {
	if a < b {
		return a
	}
	return b
}
