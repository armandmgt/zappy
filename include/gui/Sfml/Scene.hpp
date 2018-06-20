//
// EPITECH PROJECT, 2018
// ProjectName
// File description:
// SceneManager
//

#pragma once

#include <stack>
#include <memory>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "EventManager.hpp"
#include "ResourceManager.hpp"

class AScene;

class SceneManager {
public:
    explicit SceneManager(sf::RenderWindow &window) : _window(window) {}

    void event(sf::Event &event) noexcept;
    void update(float timeSinceLastFrame) noexcept;

    /*
     * Scenes Handlers
     */
    void changeScene(std::unique_ptr<AScene> scenePtr);
    void pushScene(std::unique_ptr<AScene> scenePtr);
    void popScene();
    void pauseScene();
    void resumeScene();
    void popAllAndPushScene(std::unique_ptr<AScene> scenePtr);
    /*
     * Getters
     */
    sf::RenderWindow &getWindow() const noexcept { return _window; }
    EventManager &getEventMgr() noexcept { return _evtMgr; }
private:
    sf::RenderWindow &_window;

    EventManager _evtMgr;
    ResourceManager _resourceMgr;
    std::stack<std::unique_ptr<AScene>> _scenes;
};

class AScene {
protected:
    explicit AScene(SceneManager &parent) : _parent(parent) {}

public:
    /*
     * Create a scene
     */
    template<typename T>
    static void create(SceneManager &parent)
    {
	    static_assert(std::is_base_of<AScene, T>(), "Templated parameter is not based of Ascene");
	    parent.pushScene(std::make_unique<T>(parent));
    }

    /*
     * Scene Manipulation
     */
    virtual void enter() {}
    virtual void exit() {}
    virtual void pause() {}
    virtual void resume() {}

    virtual void update(float timeSinceLastFrame) = 0;
protected:
    SceneManager &_parent;
};