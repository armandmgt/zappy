/*
** EPITECH PROJECT, 2018
** MenuScene
** File description:
** MenuScene
*/

#pragma once

#include "Scene.hpp"
#include "SfmlEvents.hpp"

class MenuScene final : public AScene, public Receiver {
public:
	explicit MenuScene(SceneManager &parent) noexcept : AScene(parent) {}

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
	void receive(const SfmlEvent &event) noexcept;
private:
};
