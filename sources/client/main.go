package main

import (
	`flag`
	`log`
)

var (
	Machine = flag.String("h", "localhost", "machine name")
	Name = flag.String("n", "", "name of the team")
	Port = flag.Int("p", 0, "port number")
)

func init() {
	flag.Parse()

	if *Port == 0 {
		log.Fatalln("Invalid port provided -- Expected positive integer")
	}
	if *Name == "" {
		log.Fatalln("Team name cannot be empty")
	}
}

func main() {
}