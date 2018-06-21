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

class MapGeneration : public BaseEvent {
public:
    explicit MapGeneration(std::vector<std::string> &&params) noexcept : _x(std::stoi(params.at(0))), _y(std::stoi(params.at(1))), _map(_y, std::vector<uint8_t>(_x, 0)) {
    	std::cout << "MAP x == (" << _x << ") && y == (" << _y << ")" << std::endl;
    }
public:
    size_t _x;
    size_t _y;
    std::vector<std::vector<uint8_t>> _map;
};
