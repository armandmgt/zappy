package main

import `net`

type Inhabitant interface {
	moveForward() // Never fails
	turnRight() // Never fails
	turnLeft() // Never fails

	look() []string
	inventory() []string
	broadcast() // Never fails

	getUnusedSlots() int64
	fork() // Never fails
	eject() bool

	take() bool
	set() bool
	incantation() int64
}

type Direction int

const (
	UPWAY    Direction = 0
	LEFTWAY    Direction = 1
	RIGHTWAY   Direction = 2
	DOWNWAY Direction = 3
)

type Client struct {
	Connection *net.TCPConn

	team string
	gameMap Map
	rotation Direction
}

///
// Socket functions
///

func (a *Client) Read(b []byte) (string, error) {
	n, e := a.Connection.Read(b)
	return string(b[:n]), e
}

func (a *Client) Write(cmd string) (e error) {
	_, e = a.Connection.Write([]byte(cmd))
	return e
}

///
// Interface implementations
///

func (a *Client) moveForward() {
	if a.rot == UPWAY {
		a.x += 1
	}
}

func (a *Client) turnRight() {
	a.rot = (a.rot - 1) % 4
}

func (a *Client) turnLeft() {
	a.rot = (a.rot + 1) % 4
}

func (a *Client) look() (s []string) {
	return s
}

func (a *Client) inventory() (s []string) {
	return s
}

func (a *Client) broadcast() {
}

func (a *Client) getUnusedSlots() (n int64) {
	return n
}

func (a *Client) fork() {
}

func (a *Client) eject() (b bool) {
	return b
}

func (a *Client) take() (b bool) {
	return b
}

func (a *Client) set() (b bool) {
	return b
}

func (a *Client) incantation() (n int64) {
	return n
}
