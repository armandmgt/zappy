package main

import (
	`strconv`
	`log`
	`fmt`
)

var Responses = map[string]func(*Client, string) {
	"msz": getMapSize, "bct": getTileContent, "tna": getTeamsNames,
	"pnw": getNewPlayerInformations, "ppo": nil, "plv": nil,
	"pin": nil, "pex": nil, "pbc": nil,
	"pic": nil, "pie": nil, "pfk": nil,
	"pdr": nil, "pgt": nil, "pdi": nil,
	"enw": nil, "eht": nil, "ebo": nil,
	"edi": nil, "sgt": nil, "sst": nil,
	"seg": nil, "smg": nil, "suc": nil,
	"sbp": nil,
}

func getMapSize(c *Client, s string) {
	arr := make([]int64, 2)
	data := getResponseData(s)
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
	data := getResponseData(s)
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
	_ = getResponseData(s)
	//TODO: keep the information somewhere...
}

func getNewPlayerInformations(_ *Client, s string) {
	newPlayer := Player{}
	data := getResponseData(s)

	num, e := strconv.Atoi(data[0])
	if e != nil {
		log.Println("[pnw]\tGot invalid player number")
		return
	}
	newPlayer.Number = int64(num)

	x, e := strconv.Atoi(data[1])
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

	o, e := strconv.Atoi(data[1])
	if e != nil {
		log.Println("[pnw]\tGot invalid player orientation")
		return
	}
	newPlayer.Orientation = Direction(o)

	l, e := strconv.Atoi(data[1])
	if e != nil {
		log.Println("[pnw]\tGot invalid player level")
		return
	}
	newPlayer.Level = int64(l)
	//TODO: Keep the new player somewhere
}
