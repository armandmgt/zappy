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

type Client struct {
	Connection *net.TCPConn
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
}

func (a *Client) turnRight() {
}

func (a *Client) turnLeft() {
}

func (a *Client) look() (s []string) {
	return s
}

func (a *Client) inventory() (s []string) {
	return s
}

func (a *Client) broadcast() {
}

func (a *Client) getUnusedSlots() (n int32) {
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

func (a *Client) incantation() (n int32) {
	return n
}
