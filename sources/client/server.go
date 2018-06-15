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
		"pin": getPlayerInventory, "pex": nil, "pbc": nil,
		"pic": nil, "pie": nil, "pfk": nil,
		"pdr": nil, "pgt": nil, "pdi": nil,
		"enw": nil, "eht": nil, "ebo": nil,
		"edi": nil, "sgt": nil, "sst": nil,
		"seg": nil, "smg": nil, "suc": nil,
		"sbp": nil,
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
	c.MapSize.X = arr[0]
	c.MapSize.Y = arr[1]
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
	newPlayer := Player{}
	data, newPlayer.Number = getProtocolResponseDataWithPlayerNumber(s)
	if len(data) == 0 {
		log.Println("Got incomplete server response")
		return
	}

	x, e := strconv.Atoi(data[0])
	if e != nil {
		log.Println("[pnw]\tGot invalid player X position")
		return
	}
	y, e := strconv.Atoi(data[1])
	if e != nil {
		log.Println("[pnw]\tGot invalid player Y position")
		return
	}
	newPlayer.Pos = Map{int64(x), int64(y)}

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
	var n int64
	data, n = getProtocolResponseDataWithPlayerNumber(s)

	if len(data) == 0 {
		log.Println("Got incomplete server response")
		return
	}
	x, e := strconv.Atoi(data[0])
	if e != nil {
		log.Println("[pnw]\tGot invalid player X position")
		return
	}
	y, e := strconv.Atoi(data[1])
	if e != nil {
		log.Println("[pnw]\tGot invalid player Y position")
		return
	}
	o, e := strconv.Atoi(data[2])
	if e != nil {
		log.Println("[pnw]\tGot invalid player orientation")
		return
	}
	//TODO: Keep those informations somewhere in the client and attach them to the correct player
	_ = n; _ = x; _ = y; _ = o
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
