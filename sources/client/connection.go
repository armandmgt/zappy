package main

import (
	`net`
	`log`
)

func openConnection() *net.TCPConn {
	var c *net.TCPConn

	tcpAddr, err := net.ResolveTCPAddr("tcp", *Machine + ":" + *Port)
	if err != nil {
	log.Fatalln("Failed to resolve host")
	}

	if c, err = net.DialTCP("tcp", nil, tcpAddr); err != nil {
	log.Fatalln(err.Error())
	}

	return c
}

func gameLoop(c *Client) {
	//buffer := make([]byte, 1024)
	isRunning := true

	for isRunning {
//		c.look(buffer)
		isRunning = false
	}
}
