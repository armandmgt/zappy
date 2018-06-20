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
    explicit App() : sf::RenderWindow(sf::VideoMode(1200, 800), "Zappy Trop bow"), _sceneMgr(*this)
    {
    }
    void init();
    void run();
private:
	SceneManager _sceneMgr;
};