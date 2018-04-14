package codewalk

import (
	"fmt"
	"testing"
)

func variadicFuncs(name ...string) {
	fmt.Println(name)
}

func TestFuncs(t *testing.T) {
	variadicFuncs("hello", "variadic", "funcs")
}
