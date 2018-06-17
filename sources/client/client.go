package main

import (
	`net`
	`fmt`
	`strings`
	`strconv`
)

type Inhabitant interface {
	moveForward() // Never fails
	turnRight() // Never fails
	turnLeft() // Never fails

	look(b []byte) bool
	inventory(b []byte) []string
	broadcast() // Never fails

	getUnusedSlots() int64
	fork() // Never fails
	eject() bool

	take() bool
	set() bool
	incantation() int64
}

type Player struct {
	MapSize Map `json:"map"`

	Vision      []string
	Pos         Map       `json:"position"`
	id          int64     `json:"number"`
	Team        string    `json:"team"`
	Level       int64     `json:"level"`
	Inventory   Inventory `json:"inventory"`
	Orientation Direction `json:"rotation"`
}

type Client struct {
	Connection *net.TCPConn `json:"connection"`

	Player *Player
	MapSize Map
}



///
// Socket functions
///

func (c *Client) Read(b []byte) (string, error) {
	n, e := c.Connection.Read(b)
	return string(b[:n]), e
}

func (c *Client) Write(cmd string) (e error) {
	_, e = c.Connection.Write([]byte(cmd))
	return e
}

///
// Interface implementations
///

func (c *Client) moveForward() {
	c.Write("Forward")
	if c.Player.Orientation == N {
		c.Player.Pos.X = (c.Player.Pos.X + 1) % c.Player.MapSize.X
	} else if c.Player.Orientation == S {
		c.Player.Pos.X = (c.Player.Pos.X - c.Player.MapSize.X) % c.Player.MapSize.X
	} else if c.Player.Orientation == E {
		c.Player.Pos.Y = (c.Player.Pos.Y + 1) % c.Player.MapSize.Y
	} else if c.Player.Orientation == W {
		c.Player.Pos.Y = (c.Player.Pos.Y - c.Player.MapSize.Y) % c.Player.MapSize.Y
	}
}

func (c *Client) turnRight() {
	c.Write("Right")
	c.Player.Orientation = (c.Player.Orientation + 1) % 4
}

func (c *Client) turnLeft() {
	c.Write("Left")
	c.Player.Orientation = (c.Player.Orientation - 1) % 4
}

func (c *Client) look(b []byte) (bool) {
//	c.Write("Look")
	//content, e := c.Read(b)
	content := "[player,,, thystame,, food,,,,,thystame ,,, player deraumere,,,]"
	//if e == nil {
	//	return false
	//}
	c.Player.Vision = getDataFromSring(content)
	for i := range c.Player.Vision {
		fmt.Printf("[%d] = %s\n", i, c.Player.Vision[i])
	}
	return true
}

func (c *Client) inventory(b []byte) (s []string) {
	c.Write("Inventory")
	content, e := c.Read(b)
	if e == nil {
		return nil
	}
	resources := getDataFromSring(content)
	for i := range resources {
		resource := strings.Split(resources[i], " ")
		value, e := strconv.Atoi(resource[1])
		if e != nil {
			fmt.Println("Error invalid number")
		}
		c.Player.Inventory[MapType[resource[0]]] = value
	}
	return s
}

func (c *Client) broadcast() {
}

func (c *Client) getUnusedSlots() (n int64) {
	return n
}

func (c *Client) fork() {
}

func (c *Client) eject() (b bool) {
	return b
}

func (c *Client) take() (b bool) {
	return b
}

func (c *Client) set() (b bool) {
	return b
}

func (c *Client) incantation() (n int64) {
	return n
}
