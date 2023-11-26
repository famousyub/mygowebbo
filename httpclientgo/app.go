
package main

import (
	"errors"
	"fmt"
	"net/http"

	"time"
	
)


const serverPort = 3333


func server(){

	mux := http.NewServeMux()
		mux.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
			fmt.Printf("server: %s /\n", r.Method)
		})
		server := http.Server{
			Addr:    fmt.Sprintf(":%d", serverPort),
			Handler: mux,
		}
		if err := server.ListenAndServe(); err != nil {
			if !errors.Is(err, http.ErrServerClosed) {
				fmt.Printf("error running http server: %s\n", err)
			}
		}
		time.Sleep(100 * time.Millisecond)

}


