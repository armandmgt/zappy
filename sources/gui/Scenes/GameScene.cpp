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