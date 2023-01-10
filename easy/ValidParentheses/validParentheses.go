package problem20

func isValid(s string) bool {
	pairs := map[rune]rune{
		'(': ')',
		'{': '}',
		'[': ']',
	}
	var stack []rune

	for _, ch := range s {
		if _, ok := pairs[ch]; ok {
			stack = append(stack, ch)
		} else if len(stack) == 0 || pairs[stack[len(stack)-1]] != ch {
			return false
		} else {
			stack = stack[:len(stack)-1]
		}
	}

	return len(stack) == 0
}
