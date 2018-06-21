/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Inventory
*/

#pragma once

#include <array>

struct Inventory {
    int &operator[](uint8_t idx) {
    	return  _resources[idx];
    }
public:
    enum ResourceType {
	Food,
	Linemate,
	Deraumere,
	Sibur,
	Mendiane,
	Phiras,
	Thystame
    };
private:
    std::array<int, 7> _resources;
};
