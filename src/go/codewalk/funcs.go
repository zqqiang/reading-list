package codewalk

import (
	"fmt"
)

func variadic_funcs(name ...string) {
	fmt.Println(name)
}

func funcsDemo() {
	variadic_funcs("hello", "variadic", "funcs")
}
