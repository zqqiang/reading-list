package main

import "github.com/gin-gonic/gin"

func main() {
	r := gin.Default()

	r.Static("/", "./public")

	r.Run(":8090")
}
