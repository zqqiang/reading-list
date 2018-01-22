// https://blog.learngoprogramming.com/golang-const-type-enums-iota-bc4befd096d3
package main

import (
	"fmt"
)

type Weekday int8

const (
	Sunday    Weekday = 0
	Monday    Weekday = 1
	Tuesday   Weekday = 2
	Wednesday Weekday = 3
	Thursday  Weekday = 4
	Friday    Weekday = 5
	Saturday  Weekday = 6
)

func (day Weekday) String() string {
	names := [...]string{
		"Sunday",
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday"}

	if day < Sunday || day > Saturday {
		return "Unknown"
	}

	return names[day]
}

func (day Weekday) Weekend() bool {
	switch day {
	case Sunday, Saturday:
		return true
	default:
		return false
	}
}

func testWeekdays() {
	fmt.Println(Sunday)
	fmt.Println(Sunday.Weekend())
}

func main() {
	testWeekdays()
}

// go get -u -a golang.org/x/tools/cmd/stringer
// stringer -type Weekday weekdays.go
