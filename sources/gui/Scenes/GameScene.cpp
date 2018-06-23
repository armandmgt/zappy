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
	_resourceMgr.loadTexture("Grass-6.png");
	_resourceMgr.loadAllTexturesInDirectory("Foods/");
}

void GameScene::displayMap() noexcept
{
	if (_started)
		for (auto &y : _map)
			for (auto &x : y)
				_parent.getWindow().draw(x.getSprite());
}

void GameScene::exit() noexcept
{
	_evtMgr.unsubscribe<SfmlEvent>(*this);
	_evtMgr.unsubscribe<MapDims>(*this);
	_evtMgr.unsubscribe<FillCellInventory>(*this);
}

void GameScene::receive(const SfmlEvent &event[[maybe_unused]]) noexcept
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		_parent.getWindow().close();
}

void GameScene::receive(const MapDims &dims) noexcept
{
	_map = std::move(std::vector(dims._y, std::vector(dims._x, Tile{})));
}

void GameScene::receive(const FillCellInventory &cell) noexcept
{
	_started = true;
	std::cout << cell._x << "," << cell._y << std::endl;

	float max = std::max(_map[0].size(), _map.size());
	float size = std::min(_parent.getWindow().getSize().x, _parent.getWindow().getSize().y) / max;
	sf::Vector2f offset((_parent.getWindow().getSize().x - (_map[0].size() * size)) / 2, (_parent.getWindow().getSize().y - (max * size)) / 2);

	auto &Tile = _map[cell._y][cell._x];
	Tile.setTileInventory(std::move(cell._inventory));
	Tile.getSprite().setTexture(_resourceMgr.getTexture("Grass-6"));
	Tile.getSprite().setScale(size / 128.0f, size / 128.0f);
	Tile.getSprite().setPosition(cell._x * size + offset.x, cell._y * size + offset.y);

}