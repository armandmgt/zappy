/*
** EPITECH PROJECT, 2018
** GameScene
** File description:
** GameScene
*/

#include "imgui.hpp"
#include "GameScene.hpp"

void GameScene::update(float timeSinceLastFrame[[maybe_unused]]) noexcept
{
	_networkMgr.updateGui();
	ImGui::ShowDemoWindow();
	ImGui::End();

	sf::Sprite sprite;
	sprite.setTexture(_resourceMgr.getTexture("0"));
	sprite.setPosition(0, 0);
	_parent.getWindow().draw(sprite);
}

void GameScene::enter() noexcept
{
	_evtMgr.subscribe<SfmlEvent>(*this);
//	_evtMgr.subscribe<MapDims>(*this);
//	_evtMgr.subscribe<FillCellInventory>(*this);
	_resourceMgr.loadTexture("0.png");
}

void GameScene::exit() noexcept
{
};

void GameScene::receive(const SfmlEvent &event[[maybe_unused]]) noexcept
{
}

