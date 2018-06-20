/*
** EPITECH PROJECT, 2018
** GameScene
** File description:
** GameScene
*/

#include "imgui.hpp"
#include "GameScene.hpp"

void GameScene::update(float timeSinceLastFrame[[maybe_unused]])
{
	_networkMgr.updateGui();
	ImGui::ShowDemoWindow();
	ImGui::End();
}

void GameScene::enter()
{
	_parent.getEventMgr().subscribe<SfmlEvent>(*this);
}

void GameScene::exit()
{
	_parent.getEventMgr().unsubscribeAll(*this);
};

void GameScene::receive(const SfmlEvent &event[[maybe_unused]]) noexcept
{

}