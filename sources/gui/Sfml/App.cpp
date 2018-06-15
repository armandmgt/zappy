/*
** EPITECH PROJECT, 2018
** App
** File description:
** App by nhyarlathotep
*/

#include "App.hpp"

void App::run()
{
	setFramerateLimit(60);
	sf::Clock deltaClock;
	while (isOpen() && _isRunning) {
		sf::Event event;
		while (pollEvent(event)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				close();
			}
		}
		clear();
		display();
	}
}