package main

import (
	`flag`
	`log`
)

var (
	Machine = flag.String("h", "localhost", "Machine name")
	Name = flag.String("n", "", "Name of the team")
	Port = flag.Int("p", 0, "Port number")
)

func init() {
	flag.Parse()

	if *Port == 0 {
		log.Fatalln("Invalid port provided -- Expected positive integer")
	}
}

func main() {
}