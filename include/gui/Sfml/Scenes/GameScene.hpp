/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** GameScene
*/

#pragma once

#include <functional>
#include "Scene.hpp"
#include "Network.hpp"
#include "SfmlEvents.hpp"

class GameScene final : public AScene, public Receiver {
public:
    explicit GameScene(SceneManager &parent) noexcept : AScene(parent) {}

    /*
     * Scene Manipulation
     */
    void enter() override;
    void exit() override;
    void update(float timeSinceLastFrame) override;
public:
    /*
     * Events Callback
     */
    void receive(const SfmlEvent &event[[maybe_unused]]) noexcept { std::cout << "SFMLEVENT" << std::endl; _parent.getEventMgr().emit<DebugEvent>(); }
    void receive(const DebugEvent &event[[maybe_unused]]) noexcept { std::cout << "DEBUG" << std::endl; }
private:
    NetworkGui _networkMgr;
};