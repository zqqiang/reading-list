package main

import (
	"github.com/gin-gonic/contrib/static"
	"github.com/gin-gonic/gin"
	"os"
)

func main() {
	r := gin.Default()

	r.Use(static.Serve("/", static.LocalFile("./public", true)))

	// add routes
	// r.GET("/api/home", controllers.Home)

	port := os.Getenv("PORT")
	if len(port) == 0 {
		port = "3000"
	}
	r.Run(":" + port)
}
