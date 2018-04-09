package codewalk

import (
	"fmt"
)

type Stringer interface {
	String() string
}

type Binary uint64

func (i Binary) String() string {
	return "test String() return"
}

func (i Binary) Get() uint64 {
	return uint64(i)
}

func interfaceDemo() {
	b := Binary(200)
	s := Stringer(b)
	fmt.Println(s.String())
}
