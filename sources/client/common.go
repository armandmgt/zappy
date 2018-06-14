package main

import `strings`

type Map struct {
	X int64 `json:"x"`
	Y int64 `json:"y"`
}
type Player struct {
	Number int64 `json:"number"`
	Team string `json:"team"`
	Pos Map `json:"position"`
	Orientation Direction `json:"orientation"`
	Level int64 `json:"level"`
}

type Direction int8
const (
	N 	Direction = 1
	E	Direction = 2
	S	Direction = 3
	W	Direction = 4
)

type Inventory [7]int64

func getResponseData(s string) []string {
	// Since all server responses start with xxx, we always cut at the 4th index
	return strings.Split(s[4:], " ")
}
