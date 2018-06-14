package main

import (
	`flag`
	`log`
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
	c := Client{co, *Name, Map{}, 0, 0, 0}

	gameLoop(c)
	defer co.Close()
}
