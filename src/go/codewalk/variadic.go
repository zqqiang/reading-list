package main

import (
	"fmt"
	"strings"
)

func toFullName(names ...string) string {
	return strings.Join(names, " ")
}

func toFullNameAppend(names ...string) []string {
	return append(names, "hey", "what's up?")
}

func testVariadic() {
	fmt.Println(toFullName("hello", "Bill"))
	fmt.Println(toFullNameAppend("Ella"))

	names := []string{"hello", "Tom"}
	fmt.Println(toFullName(names...))
}

// TODO: Variadic options pattern
// https://blog.learngoprogramming.com/golang-variadic-funcs-how-to-patterns-369408f19085

func main() {
	testVariadic()
}
