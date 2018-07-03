/*
** EPITECH PROJECT, 2018
** MenuScene
** File description:
** MenuScene by nhyarlathotep
*/

#include "GameScene.hpp"
#include "MenuScene.hpp"

void MenuScene::enter() noexcept
{
	_evtMgr.subscribe<SfmlEvent>(*this);
	_resourceMgr.loadTexture("clouds.png");
	_resourceMgr.loadTexture("Title.png");
}

void MenuScene::exit() noexcept
{
}

void MenuScene::update(float timeSinceLastFrame[[maybe_unused]]) noexcept
{
	sf::Sprite title(_resourceMgr.getTexture("Title"));
	sf::Sprite background(_resourceMgr.getTexture("clouds"));

	title.setScale(2, 2);
	title.setOrigin(title.getTexture()->getSize().x / 2, title.getTexture()->getSize().y / 2);
	title.setPosition(_parent.getWindow().getSize().x / 2, _parent.getWindow().getSize().y / 2);
	background.setScale(_parent.getWindow().getSize().x / background.getTexture()->getSize().x + 1, _parent.getWindow().getSize().y / background.getTexture()->getSize().y + 1);

	_parent.getWindow().draw(background);
	_parent.getWindow().draw(title);
}

void MenuScene::receive(const SfmlEvent &event[[maybe_unused]]) noexcept
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		_parent.getWindow().close();
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		AScene::create<GameScene>(_parent);
	}
}