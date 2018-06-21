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
    explicit GameScene(SceneManager &parent) noexcept : AScene(parent), _networkMgr(parent.getEventMgr()) {}

    /*
     * Scene Manipulation
     */
    void enter() noexcept override;
    void exit() noexcept override;
    void update(float timeSinceLastFrame) noexcept override;
public:
    /*
     * Events Callback
     */
    void receive(const SfmlEvent &event[[maybe_unused]]) noexcept;
private:
    NetworkGui _networkMgr;
};