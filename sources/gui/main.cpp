/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** main
*/

#include "ResourceManager.hpp"

namespace {
    using ResourceManager = resource::ResourceManager<sfml::ResourceManager, std::string>;
}

int main()
{
	ResourceManager resourceMgr;
	return 0;
}