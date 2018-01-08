package main

import (
    "net/http"
    "log"
)

func handler(w http.ResponseWriter, r *http.Request) {
    if pusher, ok := w.(http.Pusher); ok {
        if err := pusher.Push("/push.go", nil); err != nil {
            log.Printf("Fail to push: %v", err)
        }
    } else {
        log.Printf("ResponseWriter no http.Pusher")
    }
}

func main() {
    http.HandleFunc("/", handler)
    http.ListenAndServe(":8090", nil)
}