package codewalk

import (
	"encoding/json"
	"fmt"
	"os"
	"testing"
)

type Message struct {
	Name string
	Body string
	Time int64
}

func encoding() []byte {
	m := Message{"Alice", "Hello", 1294706395881547000}
	b, err := json.Marshal(m)
	if err != nil {
		fmt.Println(err.Error())
		return b
	}
	fmt.Println(string(b))
	return b
}

func decoding(b []byte) {
	var m Message
	err := json.Unmarshal(b, &m)
	if err != nil {
		fmt.Println(err.Error())
	}
	fmt.Println(m)
}

func generic() {
	var i interface{}
	i = "a string"
	i = 2011
	i = 2.777

	r := i.(float64)
	fmt.Println(r)

	switch v := i.(type) {
	case int:
		fmt.Println("int", v)
	case float64:
		fmt.Println("float64", v)
	case string:
		fmt.Println("string", v)
	default:
		fmt.Println("unknown type")
	}
}

func arbitray() {
	b := []byte(`{"Name":"Wednesday","Age":6,"Parents":["Gomez","Morticia"]}`)
	var f interface{}
	err := json.Unmarshal(b, &f)
	if err != nil {
		fmt.Println(err.Error())
		return
	}
	m := f.(map[string]interface{})
	fmt.Println(m)

	for k, v := range m {
		switch vv := v.(type) {
		case string:
			fmt.Println(k, "is string", vv)
		case float64:
			fmt.Println(k, "is float64", vv)
		case []interface{}:
			fmt.Println(k, "is an array:")
			for i, u := range vv {
				fmt.Println(i, u)
			}
		default:
			fmt.Println(k, "unknown type")
		}
	}
}

func stream() {
	dec := json.NewDecoder(os.Stdin)
	enc := json.NewEncoder(os.Stdout)
	for {
		var v map[string]interface{}
		if err := dec.Decode(&v); err != nil {
			fmt.Println(err.Error())
			return
		}
		for k := range v {
			if k != "Name" {
				delete(v, k)
			}
		}
		if err := enc.Encode(&v); err != nil {
			fmt.Println(err.Error())
		}
	}
}

func TestJson(t *testing.T) {

	b := encoding()

	decoding(b)

	generic()

	arbitray()

	stream()
}
