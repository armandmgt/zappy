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

	displayMap();
}

void GameScene::enter() noexcept
{
	_evtMgr.subscribe<SfmlEvent>(*this);
	_evtMgr.subscribe<MapDims>(*this);
	_evtMgr.subscribe<FillCellInventory>(*this);
	_resourceMgr.loadTexture("0.png");
	_resourceMgr.loadTexture("Grass-0.png");
}

void GameScene::displayMap() noexcept
{
	if (_started) {
		for (auto &y : _map) {
			for (auto &x : y) {
				_parent.getWindow().draw(x.getSprite());
			}
		}
	}
}

void GameScene::exit() noexcept
{
}

void GameScene::receive(const SfmlEvent &event[[maybe_unused]]) noexcept
{
}

void GameScene::receive(const MapDims &dims) noexcept
{
	_map = std::move(std::vector(dims._y, std::vector(dims._x, Tile{})));
}

void GameScene::receive(const FillCellInventory &cell) noexcept
{
	_started = true;
	auto &Tile = _map[cell._y][cell._x];

	Tile.setTileInventory(std::move(cell._inventory));
	Tile.getSprite().setTexture(_resourceMgr.getTexture("Grass-0"));
	Tile.getSprite().setScale(0.5f, 0.5f);
	Tile.getSprite().setPosition(cell._x * 64, cell._y * 64);
}