package main

import (
	`log`
	`bufio`
	`os`
	`fmt`
)

func execDebug() {
	//c := Client{nil, "foo", Map{}, 0}
	reader := bufio.NewReader(os.Stdin)

	log.Println("zappy client started in debug mode -- all input will be treated as a server response\nSend EOF to quit")
	for {
		fmt.Print("> ")
		text, _ := reader.ReadString('\n')
		if len(text) == 0 {
			break
		}
		fmt.Print(text)
	}
	os.Exit(0)
}
