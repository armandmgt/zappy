package main

import (
	`strings`
	`strconv`
	`log`
)

var Responses = map[string]func(c *Client, s string) {
	"msz": getMapSize,
	"bct": nil,
	"tna": nil,
	"pnw": nil,
	"ppo": nil,
	"plv": nil,
	"pin": nil,
	"pex": nil,
	"pbc": nil,
	"pic": nil,
	"pie": nil,
	"pfk": nil,
	"pdr": nil,
	"pgt": nil,
	"pdi": nil,
	"enw": nil,
	"eht": nil,
	"ebo": nil,
	"edi": nil,
	"sgt": nil,
	"sst": nil,
	"seg": nil,
	"smg": nil,
	"suc": nil,
	"sbp": nil,
}

func getMapSize(c *Client, s string) {
	arr := []int64{-1, -1}
	data := strings.Split(s[4:], " ")
	for i, d := range data {
		if v, e := strconv.Atoi(d); e != nil {
			log.Println("[msz]\tFailed to parse server response")
		} else {
			arr[i] = int64(v)
		}
	}
	c.gameMap.X = arr[0]
	c.gameMap.Y = arr[1]
}
