/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** GameScene
*/

#pragma once

#include <functional>
#include <unordered_map>
#include "Scene.hpp"
#include "Network.hpp"
#include "MyEvents.hpp"
#include "SfmlEvents.hpp"
#include "Tile.hpp"

class GameScene final : public AScene, public Receiver {
public:
	explicit GameScene(SceneManager &parent) noexcept : AScene(parent), _networkMgr(_evtMgr) {}

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
	void receive(const GameEnd &event) noexcept;
	void receive(const SfmlEvent &event) noexcept;
	void receive(const MapDims &event) noexcept;
	void receive(const FillCellInventory &event) noexcept;
	void receive(const NewPlayer &event) noexcept;
	void receive(const PlayerDeath &event) noexcept;
	void receive(const PlayerMoved &event) noexcept;
	void receive(const ResourceDropping &event) noexcept;
	void receive(const ResourceCollecting &event) noexcept;
private:
	void displayGame(float timeSinceLastFrame) noexcept;

	bool _started {false};
	bool _running {true};
	NetworkGui _networkMgr;
	std::vector<std::vector<Tile>> _map;
	std::unordered_map<int, Player> _players;
};
