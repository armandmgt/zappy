package main

import (
	`flag`
	`log`
)

var (
	machine = flag.String("h", "localhost", "machine name")
	name = flag.String("n", "", "name of the team")
	port = flag.Int("p", 0, "port number")
)

func init() {
	flag.Parse()

	if *port == 0 {
		log.Fatalln("Invalid port provided -- Expected positive integer")
	}
	if *name == "" {
		log.Fatalln("Team name cannot be empty")
	}
}

func main() {
}