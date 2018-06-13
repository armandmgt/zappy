package main

import `net`

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
	Connection *net.TCPConn
}

///
// Socket functions
///

func (a *Ai) Read(b []byte) (string, error) {
	n, e := a.Connection.Read(b)
	return string(b[:n]), e
}

func (a *Ai) Write(cmd string) (e error) {
	_, e = a.Connection.Write([]byte(cmd))
	return e
}

///
// Interface implementations
///

func (a *Ai) moveForward() {
}

func (a *Ai) turnRight() {
}

func (a *Ai) turnLeft() {
}

func (a *Ai) look() (s []string) {
	return s
}

func (a *Ai) inventory() (s []string) {
	return s
}

func (a *Ai) broadcast() {
}

func (a *Ai) getUnusedSlots() (n int32) {
	return n
}

func (a *Ai) fork() {
}

func (a *Ai) eject() (b bool) {
	return b
}

func (a *Ai) take() (b bool) {
	return b
}

func (a *Ai) set() (b bool) {
	return b
}

func (a *Ai) incantation() (n int32) {
	return n
}
