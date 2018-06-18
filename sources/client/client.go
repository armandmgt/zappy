package main

import (
	`net`
	`fmt`
	`strings`
	`strconv`
	`log`
)

type Player struct {
	MapSize Map `json:"map"`

	Vision      []Content  `json:"vision"`
	Pos         Map       `json:"position"`
	Id          int64     `json:"number"`
	Team        string    `json:"team"`
	Level       int64     `json:"level"`
	Inventory   Inventory `json:"inventory"`
	Orientation Direction `json:"rotation"`
}

type Client struct {
	Connection *net.TCPConn `json:"connection"`

	Player *Player
	MapSize Map `json:"mapSize"`
	SlotsLeft int64 `json:"slotsLeft"`
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
	c.Write("Look\n")
	content, e := c.Read(b)
	fmt.Println(content)
	if e != nil {
		return false
	}
	contents := getDataFromSring(content)
	for i := range contents {
		cell := strings.Split(contents[i], " ")
		for y := range cell {
			c.Player.Vision[i][CellType[cell[y]]] += 1
		}
	}
	for i := range c.Player.Vision {
		fmt.Printf("{%d}", i)
		for y := range c.Player.Vision[i] {
			fmt.Printf("[%d]", c.Player.Vision[i][y])
		}
		fmt.Printf("\n")
	}
	return true
}

func (c *Client) inventory(b []byte) (s []string) {
	c.Write("Inventory\n")
	content, e := c.Read(b)
	if e != nil {
		return nil
	}
	resources := getDataFromSring(content)
	for i := range resources {
		resource := strings.Split(resources[i], " ")
		value, e := strconv.Atoi(resource[1])
		if e != nil {
			fmt.Println("Error invalid number")
		}
		c.Player.Inventory[CellType[resource[0]]] = value
	}
	return s
}

func (c *Client) broadcast(b []byte, text string) {
}

func (c *Client) getUnusedSlots(b []byte) (n int64) {
	c.Write("Connect_nbr")
	r, e := c.Read(b)
	if e != nil {
		log.Println(e.Error())
		return
	}
	data := strings.Split(r, " ")
	v, _ := strconv.Atoi(data[0])
	c.SlotsLeft = int64(v)
	return c.SlotsLeft
}

func (c *Client) fork() {
	c.Write("Fork") // We don't need to reed since fork cannot fail
}

func (c *Client) eject(b []byte) bool {
	c.Write("Eject")
	r, e := c.Read(b)
	if e != nil {
		log.Println(e.Error())
		return false
	}
	data := strings.Split(r, " ")
	tmp, _ := strconv.Atoi(data[1])
	dir := Direction(tmp)
	switch dir {
	case N:
		c.Player.Pos.Y--
		break
	case E:
		c.Player.Pos.X--
		break
	case S:
		c.Player.Pos.Y++
		break
	case W:
		c.Player.Pos.X++
		break
	default:
		log.Println("Got invalid eject direction")
	}
	return true
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
