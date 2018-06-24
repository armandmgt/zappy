/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** MyEvents
*/

#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "Player.hpp"
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
 * Map Size
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
 * Content of a Tile
 */
class FillCellInventory : public BaseEvent {
public:
    explicit FillCellInventory(std::vector<std::string> &&params) noexcept : _x(std::stoi(params.at(0))), _y(std::stoi(params.at(1))) {
    	_inventory._resources[Inventory::ResourceType::Food] = std::move(std::vector(std::stoi(params.at(2)), std::move(sf::Sprite{})));
    	_inventory._resources[Inventory::ResourceType::Linemate] = std::move(std::vector(std::stoi(params.at(3)), std::move(sf::Sprite{})));
    	_inventory._resources[Inventory::ResourceType::Deraumere] = std::move(std::vector(std::stoi(params.at(4)), std::move(sf::Sprite{})));
    	_inventory._resources[Inventory::ResourceType::Sibur] = std::move(std::vector(std::stoi(params.at(5)), std::move(sf::Sprite{})));
    	_inventory._resources[Inventory::ResourceType::Mendiane] = std::move(std::vector(std::stoi(params.at(6)), std::move(sf::Sprite{})));
    	_inventory._resources[Inventory::ResourceType::Phiras] = std::move(std::vector(std::stoi(params.at(7)), std::move(sf::Sprite{})));
    	_inventory._resources[Inventory::ResourceType::Thystame] = std::move(std::vector(std::stoi(params.at(8)), std::move(sf::Sprite{})));
    }
public:
    int _x;
    int _y;
    Inventory _inventory;
};

/*
 * Connection of a new Player
 */
class NewPlayer : public BaseEvent {
public:
	explicit NewPlayer(std::vector<std::string> &&params) noexcept {
		_player._id = std::stoi(params.at(0));
		_player._pos = vector2d<int>{ std::stoi(params.at(1)), std::stoi(params.at(2)) };
		_player._orienation = static_cast<Player::Orientation>(std::stoi(params.at(3)));
		_player._level = std::stoi(params.at(4));
		_player._teamName = std::move(params[5]);
	}
public:
	Player _player;
};

/*
 * Player Death
 */
class PlayerDeath : public BaseEvent {
public:
	explicit PlayerDeath(std::vector<std::string> &&params) noexcept : _id(std::stoi(params.at(0))) {
	}
public:
	int _id;
};

/*
 * Resource Dropping
 */
class ResourceDropping : public BaseEvent {
public:
	explicit ResourceDropping(std::vector<std::string> &&params) noexcept : _id(std::stoi(params.at(0))), _nbResources(std::stoi(params.at(1))) {
	}
public:
	int _id;
	int _nbResources;
};

/*
 * Resource Collecting
 */
class ResourceCollecting : public BaseEvent {
public:
	explicit ResourceCollecting(std::vector<std::string> &&params) noexcept : _id(std::stoi(params.at(0))), _nbResources(std::stoi(params.at(1))) {
	}
public:
	int _id;
	int _nbResources;
};