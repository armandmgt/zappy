/*
** EPITECH PROJECT, 2018
** App
** File description:
** App by nhyarlathotep
*/

#include "App.hpp"
#include "MenuScene.hpp"
#include "GameScene.hpp"
#include "imgui-SFML.hpp"

void App::init()
{
	AScene::create<MenuScene>(_sceneMgr);
}

void App::run()
{
	/*
	 * Imgui Init
	 */
	ImGui::SFML::Init(*this);
	setFramerateLimit(60);
	sf::Clock deltaClock;
	while (isOpen()) {
		sf::Event event;
		while (pollEvent(event)) {
			_sceneMgr.event(event);
			ImGui::SFML::ProcessEvent(event);
		}
		clear();
		float timeSinceLastFrame { deltaClock.getElapsedTime().asSeconds() };
		ImGui::SFML::Update(*this, deltaClock.restart());
		_sceneMgr.update(timeSinceLastFrame);
		ImGui::SFML::Render(*this);
		display();
	}
	/*
	 * Imgui Shutdown
	 */
	ImGui::SFML::Shutdown();
}