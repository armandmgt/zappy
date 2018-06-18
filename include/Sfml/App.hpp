/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** App
*/

#pragma once

#include "Scene.hpp"
#include "ResourceManager.hpp"

class App : public sf::RenderWindow {
public:
    explicit App() : sf::RenderWindow(sf::VideoMode(1200, 800), "Zappy Trop bow")
    {
    }

    void run();

private:
    void _frameStarted(float timeSinceLastFrame) { (void)timeSinceLastFrame; };
    void _frameRenderingQueued(float timeSinceLastFrame) { (void)timeSinceLastFrame; };

    bool _isRunning{true};

    ResourceManager _resourceMgr;
};