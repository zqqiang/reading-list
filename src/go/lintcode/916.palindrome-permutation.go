/**
 * @param s: the given string
 * @return: if a permutation of the string could form a palindrome
 */
func canPermutePalindrome(s string) bool {
	// write your code here
	seen := make(map[rune]int)
	for _, r := range s {
		seen[r]++
	}
	odd := 0
	for _, m := range seen {
		if m%2 == 1 {
			odd++
		}
	}
	return odd <= 1
}
