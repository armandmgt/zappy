/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Player
*/

#pragma once

#include "Vector2d.hpp"
#include "Inventory.hpp"
#include <SFML/Graphics/RenderWindow.h>

class Player {
public:
	enum Orientation {
		UP,
		RIGHT,
		DOWN,
		LEFT
	};

	void displayPlayer(sf::RenderWindow &window) noexcept {
		window.draw()
	}
public:
	int _id;
	vector2d<int> _pos;
	Orientation _orienation;
	int _level;
	std::string _teamName;
	Inventory _inventory;
};