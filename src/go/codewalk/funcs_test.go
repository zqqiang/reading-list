package codewalk

import (
	"fmt"
	"testing"
)

func variadic_funcs(name ...string) {
	fmt.Println(name)
}

func TestFuncs(t *testing.T) {
	variadic_funcs("hello", "variadic", "funcs")
}
