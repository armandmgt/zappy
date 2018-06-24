/*
** EPITECH PROJECT, 2018
** GameScene
** File description:
** GameScene
*/

#include <random>
#include "imgui.hpp"
#include "imgui-SFML.hpp"
#include "GameScene.hpp"

void GameScene::update(float timeSinceLastFrame) noexcept
{
	_networkMgr.updateGui();
	ImGui::Image(_resourceMgr.getTexture("GreenRupee"));

	ImGui::ShowDemoWindow();
	ImGui::End();
	displayGame(timeSinceLastFrame);
}

void GameScene::displayGame(float timeSinceLastFrame) noexcept
{
	/*
	 * Display Tiles
	 */
	if (_started) {
		for (auto &y : _map) { for (auto &tile : y) { _parent.getWindow().draw(tile.getSprite()); } }
		for (auto &y : _map) { for (auto &tile : y) { tile.displayCurrentInventory(_parent.getWindow()); } }
		for (auto &player : _players) { player.second.displayPlayer(_parent.getWindow(), _resourceMgr, timeSinceLastFrame, vector2d<size_t>( _map[0].size(), _map.size() ) ); }
	}
}

void GameScene::enter() noexcept
{
	_evtMgr.subscribe<SfmlEvent>(*this);
	_evtMgr.subscribe<MapDims>(*this);
	_evtMgr.subscribe<NewPlayer>(*this);
	_evtMgr.subscribe<PlayerDeath>(*this);
	_evtMgr.subscribe<PlayerMoved>(*this);
	_evtMgr.subscribe<FillCellInventory>(*this);
	/*
	 * Resources Initialization
	 */
	_resourceMgr.loadAllTexturesInDirectory("T-0");
	_resourceMgr.loadAllTexturesInDirectory("Rupees");
	_resourceMgr.loadAnimation("Up");
	_resourceMgr.loadAnimation("Down");
	_resourceMgr.loadAnimation("Right");
	_resourceMgr.loadAnimation("Left");
}

void GameScene::exit() noexcept
{
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

	float max = std::max(_map[0].size(), _map.size());
	float size = std::min(_parent.getWindow().getSize().x, _parent.getWindow().getSize().y) / max;
	sf::Vector2f offset((_parent.getWindow().getSize().x - (_map[0].size() * size)) / 2, (_parent.getWindow().getSize().y - (_map.size() * size)) / 2);

	auto &tile = _map[cell._y][cell._x];
	tile.setTileInventory(cell._inventory);
	tile.getSprite().setTexture(_resourceMgr.getTexture("Grass-6"));
	tile.getSprite().setScale(size / 128.0f, size / 128.0f);
	tile.getSprite().setPosition(cell._x * size + offset.x, cell._y * size + offset.y);


	std::random_device random_device;
	std::mt19937 engine{random_device()};
	auto &tileInventory = tile.getInventory();

	size_t limitX = static_cast<size_t>(std::floor((128.0f * tile.getSprite().getScale().x) - (128.0f * (tile.getSprite().getScale().x / 4))));
	size_t limitY = static_cast<size_t>(std::floor((128.0f * tile.getSprite().getScale().y) - (128.0f * (tile.getSprite().getScale().y / 4))));
	for (size_t idx = 0; idx < tileInventory._resources.size(); idx++) {
		for (auto &sprite : tileInventory._resources.at(idx)) {
			sprite.setScale(tile.getSprite().getScale().x / 4, tile.getSprite().getScale().y / 4);
			sprite.setPosition(tile.getSprite().getPosition());
			sprite.setTexture(_resourceMgr.getTexture(tileInventory._resourcesPaths.at(idx)));
			size_t posX{std::uniform_int_distribution<size_t>(0, limitX)(engine)};
			size_t posY{std::uniform_int_distribution<size_t>(0, limitY)(engine)};
			sprite.setPosition(sprite.getPosition().x + posX, sprite.getPosition().y + posY);
		}
	}
}

void GameScene::receive(const NewPlayer &player) noexcept
{
	_players[player._player._id] = player._player;
	_players[player._player._id].setAnimation(_resourceMgr.getAnimation("Up"), Player::Orientation::Up);
	_players[player._player._id].setAnimation(_resourceMgr.getAnimation("Down"), Player::Orientation::Down);
	_players[player._player._id].setAnimation(_resourceMgr.getAnimation("Left"), Player::Orientation::Lelft);
	_players[player._player._id].setAnimation(_resourceMgr.getAnimation("Right"), Player::Orientation::Right);
}
void GameScene::receive(const PlayerDeath &player) noexcept
{
	_players.erase(player._id);
}

void GameScene::receive(const PlayerMoved &player) noexcept
{
	_players[player._id]._pos = vector2d<int>(player._x, player._y);
	_players[player._id]._orientation = player._orientation;
}