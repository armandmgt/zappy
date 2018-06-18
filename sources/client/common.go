package main

import (
	`strings`
	`strconv`
	`log`
)

type Map struct {
	X int64 `json:"x"`
	Y int64 `json:"y"`
}

type Direction int8
const (
	N 	Direction = 1
	E	Direction = 2
	S	Direction = 3
	W	Direction = 4
)

type InventoryType int
const (
	FOOD InventoryType = 0
	SIBUR InventoryType = 1
	PHIRAS InventoryType = 2
	MENDIANE InventoryType = 3
	TRYSTAME InventoryType = 4
	LINEMATE InventoryType = 5
	DERAUMERE InventoryType = 6
	PLAYER InventoryType = 7
)

//Map type to concord string into index in Inventory array
var CellType = map[string]InventoryType {
	"food": FOOD, "sibur": SIBUR, "phiras": PHIRAS,
	"mendiane": MENDIANE, "thystame": TRYSTAME, "linemate": LINEMATE, "deraumere": DERAUMERE,
	"player": PLAYER,
}

type Content [8]int

type Inventory map[InventoryType]int64

func getProtocolResponseData(s string) (a []string) {
	// Since all server responses start with xxx, we always cut at the 4th index
	if len(s) == 3 {
		return a
	}
	return strings.Split(s[4:], " ")
}

func getDataFromSring(s string) []string  {
	s = strings.Trim(s, "[]")
	values := strings.Split(s, ",")
	for i := range values {
		values[i] = strings.TrimLeft(values[i], " ")
		values[i] = strings.TrimRight(values[i], " ")
	}
	return values
}

func getProtocolResponseDataWithPlayerNumber(s string) (a []string, _ int64) {
	// Since all server responses start with xxx, we always cut at the 4th index
	if len(s) == 3 {
		return a, 0
	}
	a = strings.Split(s[4:], " ")
	t, e := strconv.Atoi(a[0])
	if e != nil {
		return a, -1
	}
	return a[1:], int64(t)
}

func getPosition(s1, s2 string) (m Map, e error) {
	x, e := strconv.Atoi(s1)
	if e != nil {
		log.Println("Got invalid player X position")
		return Map{}, e
	}
	y, e := strconv.Atoi(s2)
	if e != nil {
		log.Println("Got invalid player Y position")
		return Map{}, e
	}
	return Map{int64(x), int64(y)}, nil
}
