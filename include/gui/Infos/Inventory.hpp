/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Inventory
*/

#pragma once

#include <array>
#include <string>

struct Inventory {
    int &operator[](uint8_t idx) noexcept {
    	return  _resources[idx];
    }
    std::string getTextureName(uint8_t idx) const noexcept {
	    return _resourcesPaths.at(idx);
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
    std::array<std::string, 7> _resourcesPaths { { {"0"}, {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"} } };
};
