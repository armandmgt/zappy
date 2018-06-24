/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Inventory
*/

#pragma once

#include <array>
#include <unordered_map>
#include <utility>
#include <string>
#include <SFML/Graphics/Sprite.hpp>

struct Inventory {
public:
	 enum ResourceType {
		Food,
		Linemate,
		Deraumere,
		Sibur,
		Mendiane,
		Phiras,
		Thystame,
		Count
	};
	std::array<std::vector<sf::Sprite>, ResourceType::Count> _resources;
	std::array<std::string, ResourceType::Count> _resourcesPaths{{{"GreenRupee"}, {"BlueRupee"}, {"RedRupee"}, {"PurpleRupee"}, {"YellowRupee"}, {"OrangeRupee"}, {"Heart"}}};
	std::unordered_map<std::string, Inventory::ResourceType> _resourcesName {
		{"Food", ResourceType::Food},
		{"Linemate", ResourceType::Linemate},
		{"Deraumere", ResourceType::Deraumere},
		{"Sibur", ResourceType::Sibur},
		{"Mendiane", ResourceType::Mendiane},
		{"Phiras", ResourceType::Phiras},
		{"Thystame", ResourceType::Thystame}
	};
};
