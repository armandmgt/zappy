package main

type Inhabitant interface {
	moveForward() // Never fails
	turnRight() // Never fails
	turnLeft() // Never fails

	look() []string
	inventory() []string
	broadcast() // Never fails

	getUnusedSlots() int32
	fork() // Never fails
	eject() bool

	take() bool
	set() bool
	incantation() int32
}

type Ai struct {
}