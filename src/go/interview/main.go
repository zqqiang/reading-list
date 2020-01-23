package main

// IsUnique 1.1
// Implement an algorithm to determine if a string has all unique characters.
// What if you cannot use additional data structures?
func IsUnique(str string) bool {
	seen := make(map[rune]int)
	for _, v := range str {
		if _, ok := seen[v]; ok {
			return false
		}
		seen[v]++
	}
	return true
}

// CheckPermutation 1.2
// Leetcode 567
// Check Permutation: Given two strings, write a method to decide if one is a permutation of the other.
func checkInclusion(s1 string, s2 string) bool {
	seen := make(map[byte]int)
	if len(s1) > len(s2) {
		return false
	}
	for i := 0; i < len(s1); i++ {
		seen[s1[i]]++
		seen[s2[i]]--
	}
	if AllZero(seen) {
		return true
	}
	for i := len(s1); i < len(s2); i++ {
		seen[s2[i]]--
		seen[s2[i-len(s1)]]++
		if AllZero(seen) {
			return true
		}
	}
	return false
}

func AllZero(seen map[byte]int) bool {
	for _, v := range seen {
		if v != 0 {
			return false
		}
	}
	return true
}
