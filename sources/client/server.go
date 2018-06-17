package main

import (
	`strconv`
	`log`
	`fmt`
)

var (
	Responses = map[string]func(*Client, string) {
		"msz": getMapSize, "bct": getTileContent, "tna": getTeamsNames,
		"pnw": getNewPlayerInformations, "ppo": getPlayerPosition, "plv": getPlayerLevel,
		"pin": getPlayerInventory, "pex": excludePlayer, "pbc": broadcast,
		"pic": startIncantation, "pie": endIncantation, "pfk": layEgg,
		"pdr": dropRessource, "pgt": collectRessource, "pdi": handlePlayerDeath,
		"enw": getLayingData, "eht": eggHatching, "ebo": handleEggConnection,
		"edi": eggDeath, "sgt": getTimeUnit, "sst": getTimeUnitModification,
		"seg": endGame, "smg": handleServerMessage, "suc": unknownCommand,
		"sbp": commandParameter,
	}

	data []string
)


func getMapSize(c *Client, s string) {
	arr := make([]int64, 2)
	data = getProtocolResponseData(s)
	if len(data) == 0 {
		log.Println("Got incomplete server response")
		return
	}

	for i, d := range data {
		if v, e := strconv.Atoi(d); e != nil {
			log.Println("[msz]\tFailed to parse server response")
			fmt.Println(e.Error())
			return
		} else {
			arr[i] = int64(v)
		}
	}
	c.Player.MapSize.X = arr[0]
	c.Player.MapSize.Y = arr[1]
}

func getTileContent(_ *Client, s string) {
	var arr []int64
	data = getProtocolResponseData(s)
	if len(data) == 0 {
		log.Println("Got incomplete server response")
		return
	}

	for _, d := range data {
		if v, e := strconv.Atoi(d); e != nil {
			log.Println("[bct]\tFailed to parse server response")
			fmt.Println(e.Error())
			return
		} else {
			arr = append(arr, int64(v))
		}
	}
	//TODO: keep the information somewhere...
}

func getTeamsNames(_ *Client, s string) {
	_ = getProtocolResponseData(s)
	//TODO: keep the information somewhere...
}

func getNewPlayerInformations(_ *Client, s string) {
	var pos Map
	newPlayer := Player{}
	data, newPlayer.id = getProtocolResponseDataWithPlayerNumber(s)
	if len(data) == 0 {
		log.Println("Got incomplete server response")
		return
	}

	num, e := strconv.Atoi(data[0])
	if e != nil {
		log.Println("[pnw]\tGot invalid player number")
		return
	}
	newPlayer.id = int64(num)

	pos, e = getPosition(data[1], data[2])
	if e != nil {
		return
	}
	newPlayer.Pos = pos

	o, e := strconv.Atoi(data[2])
	if e != nil {
		log.Println("[pnw]\tGot invalid player orientation")
		return
	}
	newPlayer.Orientation = Direction(o)

	l, e := strconv.Atoi(data[3])
	if e != nil {
		log.Println("[pnw]\tGot invalid player level")
		return
	}
	newPlayer.Level = int64(l)
	newPlayer.Team = data[4]
	//TODO: Keep the new player somewhere
}

func getPlayerPosition(_ *Client, s string) {
	var pos Map
	var e error
	var n int64
	data, n = getProtocolResponseDataWithPlayerNumber(s)
	if len(data) == 0 {
		log.Println("Got incomplete server response")
		return
	}

	pos, e = getPosition(data[0], data[1])
	if e != nil {
		return
	}

	o, e := strconv.Atoi(data[2])
	if e != nil {
		log.Println("[pnw]\tGot invalid player orientation")
		return
	}
	//TODO: Keep those informations somewhere in the client and attach them to the correct player
	_ = n; _ = pos; _ = o
}

func getPlayerLevel(_ *Client, s string) {
	var n int64
	data, n = getProtocolResponseDataWithPlayerNumber(s)
	level, e := strconv.Atoi(data[1])
	if e != nil {
		log.Println("[plv]\tGot invalid player level")
		return
	}
	//TODO: Attach the information to the corresponding player
	_ = level; _ = n
}

func getPlayerInventory(_ *Client, s string) {
	var arr []int64
	var n int64
	data, n = getProtocolResponseDataWithPlayerNumber(s)
	if len(data) == 0 {
		log.Println("Got incomplete server response")
		return
	}

	for _, d := range data {
		if v, e := strconv.Atoi(d); e != nil {
			log.Println("[pin]\tFailed to parse server response")
			fmt.Println(e.Error())
			return
		} else {
			arr = append(arr, int64(v))
		}
	}
	//TODO: keep the information somewhere...
	_ = n
}

func excludePlayer(_ *Client, s string) {
	var n int64
	data, n = getProtocolResponseDataWithPlayerNumber(s)
	//TODO: remove player from player array
	_ = n
}

func broadcast(_ *Client, s string) {
	var n int64
	data, n = getProtocolResponseDataWithPlayerNumber(s)
	msg := data[0]
	//TODO: ???
	_ = n; _ = msg
}

func startIncantation(_ *Client, s string) {
	var pos Map
	var e error
	var playerNames []int64
	data = getProtocolResponseData(s)

	pos, e = getPosition(data[0], data[1])
	if e != nil {
		return
	}

	l, e := strconv.Atoi(data[2])
	if e != nil {
		log.Println("[pic]\tGot invalid player level")
		return
	}
	for _, n := range data[2:] {
		num, e := strconv.Atoi(n)
		if e != nil {
			log.Println("[pic]\tGot invalid player number")
			return
		}
		playerNames = append(playerNames, int64(num))
	}
	//TODO: ???
	_ = pos; _ = l
}

func endIncantation(_ *Client, s string) {
	var pos Map
	var e error
	data := getProtocolResponseData(s)
	if len(data) == 0 {
		log.Println("Got incomplete server response")
		return
	}

	pos, e = getPosition(data[0], data[1])
	if e != nil {
		return
	}

	//TODO: use data[2] once we get the correct format
	_ = pos
}

func layEgg(_ *Client, s string) {
	_, n := getProtocolResponseDataWithPlayerNumber(s)
	_ = n
}

func dropRessource(_ *Client, s string) {
	data, n := getProtocolResponseDataWithPlayerNumber(s)
	i, e := strconv.Atoi(data[0])
	if e != nil {
		log.Println("[pdr]\tGot invalid ressource quantity")
		return
	}
	//TODO: use data
	_ = n; _ = i
}

func collectRessource(_ *Client, s string) {
	data, n := getProtocolResponseDataWithPlayerNumber(s)
	i, e := strconv.Atoi(data[0])
	if e != nil {
		log.Println("[pgt]\tGot invalid ressource quantity")
		return
	}
	//TODO: use data
	_ = n; _ = 1
}

func handlePlayerDeath(_ *Client, s string) {
	_, n := getProtocolResponseDataWithPlayerNumber(s)
	//TODO: remove player from list of active players
	_ = n
}

func getLayingData(_ *Client, s string) {
	data, egg := getProtocolResponseDataWithPlayerNumber(s) //WARN: e is the egg number -> not the player
	n, e := strconv.Atoi(data[0])
	if e != nil {
		log.Println("[enw]\tGot invalid player number")
		return
	}
	pos, e := getPosition(data[1], data[2])
	if e != nil {
		return
	}
	//TODO: keep this info somewhere
	_ = egg; _ = n; _ = pos
}

func eggHatching(_ *Client, s string) {
	_, egg := getProtocolResponseDataWithPlayerNumber(s)
	//TODO: keep the info somewhere
	_ = egg
}

func handleEggConnection(_ *Client, s string) {
	_, egg := getProtocolResponseDataWithPlayerNumber(s)
	//TODO: handle the connection
	_ = egg
}

func eggDeath(_ *Client, s string) {
	_, egg := getProtocolResponseDataWithPlayerNumber(s)
	//TODO: pop the egg from the egg list I guess...
	_ = egg
}

func getTimeUnit(_ *Client, s string) {
	data := getProtocolResponseData(s)
	if len(data) == 0 {
		log.Println("[sgt]\tGot empty time unit")
		return
	}
	//TODO: what the fuck is this supposed to be ?
}

func getTimeUnitModification(_ *Client, s string) {
	data := getProtocolResponseData(s)
	if len(data) == 0 {
		log.Println("[sgt]\tGot empty time unit")
		return
	}
	//TODO: what the fuck is this supposed to be ?
}

func endGame(_ *Client, s string) {
	data := getProtocolResponseData(s)
	if len(data) == 0 {
		log.Println("[seg]\tGot empty team name")
		return
	}
	winnerTeam := data[0] //TODO: I guess ???
	_ = winnerTeam
}

func handleServerMessage(_ *Client, s string) {
	data := getProtocolResponseData(s)
	if len(data) == 0 {
		return
	}
	fmt.Println("[SERVER]\t", data[0])
}

func unknownCommand(_ *Client, _ string) {
	return
}

func commandParameter(_ *Client, _ string) {
	return
}
