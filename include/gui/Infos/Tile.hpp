/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Tile
*/

#pragma once

#include <SFML/Graphics/Sprite.h>
#include "Inventory.hpp"

class Tile {
public:
	explicit Tile() = default;

	void setTileInventory(const Inventory &inventory) noexcept {
		_inventory = inventory;
	}
	sf::Sprite &getSprite() noexcept {
		return _sprite;
	}
private:
	sf::Sprite _sprite;
	Inventory _inventory;
};