package problem944

func minDeletionSize(strs []string) int {
	sorted := 0
	for i := 0; i < len(strs[0]); i++ {
		for j, str := range strs[1:] {
			if str[i] < strs[j][i] {
				sorted++
				break
			}
		}
	}
	return sorted
}
