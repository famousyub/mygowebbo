package main

import (
	"flag"
	"log"
	"net/http"

	"github.com/gin-gonic/gin"
	"github.com/gorilla/websocket"
)

var (
	certPath string
	keyPath  string
	address  string
)

func init() {
	flag.StringVar(&certPath, "cert", "", "path to SSL/TLS certificate file")
	flag.StringVar(&keyPath, "key", "", "path to SSL/TLS private key file")
	flag.StringVar(&address, "a", ":7000", "address to use")
}

var upgrader2 = websocket.Upgrader{
	ReadBufferSize:  1024,
	WriteBufferSize: 1024,
	CheckOrigin: func(r *http.Request) bool {
		return true
	},
}

func mainsocket() {
	flag.Parse()

	router := gin.Default()

	// Serve HTML page to trigger connection
	router.GET("/", func(c *gin.Context) {
		c.File("index2.html")
	})

	// Handle WebSocket connections
	router.GET("/ws", func(c *gin.Context) {
		conn, err := upgrader2.Upgrade(c.Writer, c.Request, nil)
		if err != nil {
			// panic(err)
			log.Printf("%s, error while Upgrading websocket connection\n", err.Error())
			c.AbortWithError(http.StatusInternalServerError, err)
			return
		}

		for {
			// Read message from client
			messageType, p, err := conn.ReadMessage()
			if err != nil {
				// panic(err)
				log.Printf("%s, error while reading message\n", err.Error())
				c.AbortWithError(http.StatusInternalServerError, err)
				break
			}

			// Echo message back to client
			err = conn.WriteMessage(messageType, p)
			if err != nil {
				// panic(err)
				log.Printf("%s, error while writing message\n", err.Error())
				c.AbortWithError(http.StatusInternalServerError, err)
				break
			}
		}
	})

	if certPath == "" || keyPath == "" {
		log.Println("Warning: SSL/TLS certificate and/or private key file not provided. Running server unsecured.")
		err := router.Run(address)
		if err != nil {
			panic(err)
		}
	} else {
		err := router.RunTLS(address, certPath, keyPath)
		if err != nil {
			panic(err)
		}
	}
}