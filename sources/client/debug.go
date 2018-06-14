package main

import (
	`bufio`
	`os`
	`fmt`
	`encoding/json`
	`log`
)

func runCmd(c *Client, s string) {
	if s == "dump" {
		clientAsJSON, e := json.MarshalIndent(c, "", "\t")
		if e != nil {
			fmt.Println("failed to parse client")
			return
		}
		fmt.Println(string(clientAsJSON))
		return
	}

	if function, ok := Responses[s[:3]]; !ok {
		fmt.Println("Invalid command provided")
	} else {
		if function == nil {
			fmt.Println("Function not implemented")
		} else {
			function(c, s)
		}
	}
}

func execDebug() {
	var cmd string
	c := Client{nil, "foo", Map{}, 0, 0, 0}
	reader := bufio.NewReader(os.Stdin)

	debugGreeting()
	for {
		fmt.Print("> ")
		if cmd, _ = reader.ReadString('\n'); len(cmd) == 0 {
			break
		}
		if len(cmd) > 3 {
			runCmd(&c, cmd[:len(cmd) - 1])
		}
	}
	os.Exit(0)
}

func debugGreeting() {
	log.Println("zappy client started in debug mode -- all input will be treated as a server response")
	fmt.Println("Send EOF to quit")
	fmt.Println("\nList of builtins:")
	fmt.Println("- dump:\tdumps the client as json")
}
