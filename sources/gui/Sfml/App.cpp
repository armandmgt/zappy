/*
** EPITECH PROJECT, 2018
** App
** File description:
** App by nhyarlathotep
*/

#include "App.hpp"
#include "imgui-SFML.hpp"

void App::init()
{

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
		float timeSinceLastFrame { deltaClock.getElapsedTime().asSeconds() };
		ImGui::SFML::Update(*this, deltaClock.restart());
		_sceneMgr.update(timeSinceLastFrame);
		clear();
		ImGui::SFML::Render(*this);
		display();
	}
	/*
	 * Imgui Shutdown
	 */
	ImGui::SFML::Shutdown();
}