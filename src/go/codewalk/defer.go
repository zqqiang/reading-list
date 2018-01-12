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

func Count(i int) (n int) {
	defer func(i int) {
		n = n + i
	}(i)
	i = i * 2
	n = i
	return
}

type Car struct {
	model string
}

func (c Car) PrintModelByObj() {
	fmt.Println(c.model)
}

func (c *Car) PrintModelByPointer() {
	fmt.Println(c.model)
}

func DeferedMethod() {
	c := Car{model: "Benz"}

	defer c.PrintModelByObj()

	c.model = "Toyota"

	p := &Car{model: "Benz"}

	defer p.PrintModelByPointer()

	p.model = "Toyota"
}

func main() {
	example()

	NewFromFile("json.go")

	Panic()

	Closure()

	fmt.Println("Count:", Count(10))

	DeferedMethod()
}
