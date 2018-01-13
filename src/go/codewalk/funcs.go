package main

import (
	"fmt"
)

func variadic_funcs(name ...string) {
	fmt.Println(name)
}

func main() {

	variadic_funcs("hello", "variadic", "funcs")
}
