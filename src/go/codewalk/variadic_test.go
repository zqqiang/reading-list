// https://blog.learngoprogramming.com/golang-variadic-funcs-how-to-patterns-369408f19085

package codewalk

import (
	"fmt"
	"strings"
	"testing"
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

//Variadic options pattern
type verbosity int

const (
	// Default logging is Low (zero-value of an int).
	Low = verbosity(iota)
	Medium
	High
)

type Logger struct {
	verbosity verbosity
	prefix    string
}

type option func(*Logger)

func (lo *Logger) SetOptions(opts ...option) {
	for _, applyOptTo := range opts {
		applyOptTo(lo)
	}
}

func HighVerbosity() option {
	return func(lo *Logger) {
		lo.verbosity = High
	}
}

func Prefix(s string) option {
	return func(lo *Logger) {
		lo.prefix = s
	}
}

// Critical logs when something bad has happened.
func (lo *Logger) Critical(s string) {
	lo.print("CRITICAL", s)
}

// Info logs just for informational messages.
func (lo *Logger) Info(s string) {
	if lo.verbosity > Medium {
		lo.print("INFO", s)
	}
}

func (lo *Logger) print(level string, msg string) {
	pre := ""

	if lo.prefix != "" {
		// not optimized - just an example.
		pre = "[" + lo.prefix + "] "
	}

	fmt.Printf("%s%-10s: %s\n", pre, level, msg)
}

func testLogger() {
	logger := &Logger{}
	logger.SetOptions(
		HighVerbosity(),
		Prefix("ZOMBIE CONTROL"),
	)
	logger.Critical("zombie critical")
	logger.Info("1 second passed")
}

func TestVariadic(t *testing.T) {
	testVariadic()
	testLogger()
}
