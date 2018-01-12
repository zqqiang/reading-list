package main

import (
	"encoding/json"
	"fmt"
	"os"
)

func example() {
	defer func() {
		fmt.Println("later")
	}()
	fmt.Println("first")
}

type Config struct {
	id string
}

func NewFromFile(path string) (c *Config, err error) {
	c = &Config{}

	file, err := os.Open(path)
	if err != nil {
		return
	}

	defer func() {
		fmt.Println("file close")
		file.Close()
	}()

	err = json.NewDecoder(file).Decode(c)
	if err != nil {
		return
	}
	return
}

func Panic() {
	defer func() {
		if err := recover(); err != nil {
			fmt.Println("recover", err)
		}
	}()
	panic("oops!")
}

func Closure() {
	num := 1
	defer func() {
		fmt.Println("defer", num)
	}()
	num = 2
}

func main() {
	example()

	NewFromFile("json.go")

	Panic()

	Closure()
}
