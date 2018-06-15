 package main

import (
	`flag`
	`log`
	`net`
)

var (
	Machine = flag.String("h", "127.0.0.1", "Machine name")
	Name = flag.String("n", "", "Name of the team")
	Port = flag.String("p", "", "Port number")
	Debug = flag.Bool("debug", false, "debug mode")
)

func init() {
	flag.Parse()

	if *Debug {
		execDebug()
	}
	if *Port == "" {
		log.Fatalln("Invalid port provided -- Expected positive integer")
	}
	if *Machine == "localhost" {
		*Machine = "127.0.0.1"
	}
}

func main() {
	co := openConnection()
	c := &Client{}

	initClient(c, co)
	gameLoop(c)
	defer co.Close()
}

func initClient(c *Client, co *net.TCPConn) {
	c.Connection = co
	c.Player = &Player{Map{0, 0}, nil, Map{0, 0},
	0, *Name, 1, Inventory{0,0,0,0,0,0,0}, N}
}
