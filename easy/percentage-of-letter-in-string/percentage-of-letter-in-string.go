package problem2278

func percentageLetter(s string, letter byte) int {
	var count int

	if len(s) < 0 {
		return 0
	}

	for char := 0; char < len(s); char++ {
		if string(s[char]) == string(letter) {
			count++
		}
	}

	return (count * 100) / len(s)
}
