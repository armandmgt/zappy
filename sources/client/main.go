 package main

import (
	`flag`
	`log`
	`net`
	`strconv`
	`strings`
)

var (
	Machine = flag.String("h", "127.0.0.1", "Machine name")
	Name = flag.String("n", "", "Name of the team")
	Port = flag.String("p", "", "Port number")
	Debug = flag.Bool("debug", false, "debug mode")
)

func init() {
	flag.Parse()

	if *Debug {
		execDebug()
	}
	if *Port == "" {
		log.Fatalln("Invalid port provided -- Expected positive integer")
	}
	if *Machine == "localhost" {
		*Machine = "127.0.0.1"
	}
}

 func initClient(c *Client, co *net.TCPConn)  {
	 c.Connection = co
	 buffer := make([]byte, 1024)
	 if s, e := c.Read(buffer); s != "WELCOME\n" || e != nil {
		 log.Fatalln("Received invalid first response\nGot:", s)
	 }
	 c.Write(*Name+"\n")
	 numStr, _ := c.Read(buffer)
	 lines := strings.Split(numStr, "\n")
	 id , _ := strconv.Atoi(lines[0])
	 posArr := strings.Split(lines[1], " ")
	 X, _ :=  strconv.Atoi(posArr[0])
	 Y, _ :=  strconv.Atoi(posArr[1])
	 invent := make([]Content, 49)
	 c.Player = &Player{Map{0, 0}, invent, Map{int64(X), int64(Y)},
		 int64(id), *Name, 1, Inventory{0,0,0,0,0,0,0}, N}
		 c.look(buffer)
}


func main() {
	co := openConnection()
	c := &Client{}

	initClient(c, co)
	gameLoop(c)
	defer co.Close()
}
