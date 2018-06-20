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
    explicit GameScene(SceneManager &parent) noexcept : AScene(parent) {
	    parent.getEventMgr().subscribe<SfmlEvent>(*this);
    }

    void update(float timeSinceLastFrame) override;
public:
    /*
     * Events Callback
     */
    void receive(const SfmlEvent &event[[maybe_unused]]) noexcept {}
private:
    NetworkGui _networkMgr;
};