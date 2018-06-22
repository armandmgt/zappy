/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** MyEvents
*/

#pragma once

#include <vector>
#include <iostream>
#include <sstream>
#include "Inventory.hpp"
#include "EventManager.hpp"

/*
 * Only NetworkGui use this Event
 */
class MsgEvent : public BaseEvent {
public:
    explicit MsgEvent(std::string &&msg) noexcept {
	    std::stringstream epur(std::move(msg));

	    epur >> _command;
	    for (std:: string tmp; epur >> tmp; _params.push_back(std::move(tmp)));
    }
public:
    std::string _command;
    std::vector<std::string> _params;
};

/*
 * Msz Command
 */
class MapDims : public BaseEvent {
public:
    explicit MapDims(std::vector<std::string> &&params) noexcept : _x(std::stoi(params.at(0))), _y(std::stoi(params.at(1))) {
    }
public:
    int _x;
    int _y;
};

/*
 * Mct Command
 */
#include <iostream>

class FillCellInventory : public BaseEvent {
public:
    explicit FillCellInventory(std::vector<std::string> &&params) noexcept : _x(std::stoi(params.at(0))), _y(std::stoi(params.at(1))) {
    	_inventory[Inventory::ResourceType::Food] = std::stoi(params.at(2));
    	_inventory[Inventory::ResourceType::Linemate] = std::stoi(params.at(3));
    	_inventory[Inventory::ResourceType::Deraumere] = std::stoi(params.at(4));
    	_inventory[Inventory::ResourceType::Sibur] = std::stoi(params.at(5));
    	_inventory[Inventory::ResourceType::Mendiane] = std::stoi(params.at(6));
    	_inventory[Inventory::ResourceType::Phiras] = std::stoi(params.at(7));
    	_inventory[Inventory::ResourceType::Thystame] = std::stoi(params.at(8));
    }
public:
    int _x;
    int _y;
    Inventory _inventory;
};
