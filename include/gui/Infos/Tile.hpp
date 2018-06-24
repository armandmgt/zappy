/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Tile
*/

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "Inventory.hpp"

class Tile {
public:
	explicit Tile() = default;

	void setTileInventory(const Inventory &inventory) noexcept { _inventory = inventory; }

	sf::Sprite &getSprite() noexcept { return _tileSprite; }

	Inventory &getInventory() noexcept { return _inventory; };

	void displayCurrentInventory(sf::RenderWindow &window) {
		for (size_t idx = 0; idx < _inventory._resources.size(); idx++) {
			for (auto &sprite : _inventory._resources.at(idx)) {
				window.draw(sprite);
			}
		}
	}

private:
	sf::Sprite _tileSprite;
	Inventory _inventory;
};