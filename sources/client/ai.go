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
	N 	Direction = 1
	E	Direction = 2
	S	Direction = 3
	W	Direction = 4
)

type Client struct {
	Connection *net.TCPConn `json:"connection"`

	Team string `json:"team"`
	MapSize Map `json:"map"`
	Orientation Direction `json:"rotation"`
	X int64 `json:"x"`
	Y int64 `json:"y"`
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
	if a.Orientation == N {
		a.X += 1
	} else if a.Orientation == S {
		a.X -= 1
	} else if a.Orientation == E {
		a.Y += 1
	} else if a.Orientation == W {
		a.Y -= 1
	}
}

func (a *Client) turnRight() {
	a.Orientation = (a.Orientation - 1) % 4
}

func (a *Client) turnLeft() {
	a.Orientation = (a.Orientation + 1) % 4
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
