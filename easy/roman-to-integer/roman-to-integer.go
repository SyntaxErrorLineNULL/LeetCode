package roman_to_integer

func romanToInt(s string) int {
	roman := map[string]int{
		"I": 1,
		"V": 5,
		"X": 10,
		"L": 50,
		"C": 100,
		"D": 500,
		"M": 1000,
	}

	size := len(s)

	num := roman[string(s[size-1])]
	for i := size - 2; i >= 0; i-- {
		if roman[string(s[i])] >= roman[string(s[i+1])] {
			num += roman[string(s[i])]
		} else {
			num -= roman[string(s[i])]
		}
	}

	return num
}
