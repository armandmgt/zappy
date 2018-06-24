/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Player
*/

#pragma once

#include <array>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Vector2d.hpp"
#include "Inventory.hpp"
#include "ResourceManager.hpp"


#include <iostream>

class Player {
public:
	enum Orientation {
		Up = 1,
		Right = 2,
		Down = 3,
		Lelft = 4,
		Count = 4
	};

	void displayPlayer(sf::RenderWindow &window, ResourceManager &resourceMgr, float timeSinceLastFrame, vector2d<size_t> mapSize) noexcept {
		sf::Sprite sprite;
		sprite.setTexture(resourceMgr.getTexture(_animations[_orientation - 1].addTime(timeSinceLastFrame)));

		float max = std::max(mapSize.x, mapSize.y);
		float size = std::min(window.getSize().x, window.getSize().y) / max;
		sf::Vector2f offset((window.getSize().x - (mapSize.x * size)) / 2, (window.getSize().y - (mapSize.x * size)) / 2);

		sprite.setScale(size / sprite.getTexture()->getSize().x, (size / sprite.getTexture()->getSize().y));
		sprite.setPosition(_pos.x * size + offset.x, _pos.y * size + offset.y);
		window.draw(sprite);
	}

	void setAnimation(AnimationState &anim, int idx) noexcept {
		_animations[idx - 1] = anim;
	}
public:
	int _id;
	int _level;
	vector2d<int> _pos;
	Orientation _orientation;
	std::string _teamName;
	Inventory _inventory;
	std::array<AnimationState, Count> _animations;
};