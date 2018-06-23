/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** App
*/

#pragma once

#include "Scene.hpp"

class App : public sf::RenderWindow {
public:
    explicit App() : sf::RenderWindow(sf::VideoMode(1800, 1000), "Zappy Trop bow", sf::Style::Fullscreen), _sceneMgr(*this)
    {
    }
    void init();
    void run();
private:
	SceneManager _sceneMgr;
};