//
// EPITECH PROJECT, 2018
// Zappy
// File description:
// ResourcesManager
//

#pragma once

#include <iostream>
#include <unordered_map>
#include <experimental/filesystem>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

template<typename Resource>
class ResourceHolder {
public:
    explicit ResourceHolder() noexcept = default;

    template<typename ...Args>
    Resource &load(const std::string &id, Args &&...args)
    {
	    Resource res;

	    if (!res.loadFromFile(std::forward<Args>(args)...)) {
		    throw std::runtime_error("Impossible to load file");
	    }

	    if (!_resources.emplace(id, std::move(res)).second) {
		    std::cout << "Object already exists" << std::endl;
		    return get(id);
	    }
	    return _resources[id];
    }

    void remove(const std::string &id) noexcept
    {
	    if (_resources.find(id) != _resources.end()) {
		    _resources.erase(id);
	    }
    }

    Resource &get(const std::string &id)
    {
	    return _resources.at(id);
    }

    template<typename ...Args>
    Resource &getOrLoad(const std::string &id, Args &&...args)
    {
	    if (_resources.find(id) == _resources.end()) {
		    return load(id, std::forward<Args>(args)...);
	    }
	    return get(id);
    }

    void clear() noexcept
    {
	    _resources.clear();
    }

private:
    std::unordered_map<std::string, Resource> _resources;
};

class AnimationState {
public:
	explicit AnimationState() = default;

	std::vector<std::string> &getAnimations() noexcept { return _animations; }

	std::string addTime(float timeSinceLastFrame) noexcept {
		_time += timeSinceLastFrame;
		if (_time > _frameRate * _animations.size()) {
			_time = 0;
			_index = 0;
		}
		if (_time > _frameRate * (_index + 1))
			_index += 1;
		return _animations[_index];
	}
private:
	float _frameRate {0.2f};
	float _time {0};
	size_t _index {0};
	std::vector<std::string> _animations;
};

class ResourceManager {
public:
    using MusicRegistry = ResourceHolder<sf::Music>;
    using TexturesRegistry = ResourceHolder<sf::Texture>;

    explicit ResourceManager(std::experimental::filesystem::path resourceDirectoryPath = (std::experimental::filesystem::current_path() / "assets")) noexcept : _resourceDirectoryPath(resourceDirectoryPath) {
    	std::cout << _resourceDirectoryPath << std::endl;
    }
public:
    /*
     * Just give it the texture's name
     * If the texture is in _resourceDirectoryPath(default = "assets/")
     */
    sf::Texture &loadTexture(const std::experimental::filesystem::path &filename) {
    	std::experimental::filesystem::path id = filename;
    	for (auto &it : std::experimental::filesystem::recursive_directory_iterator(_resourceDirectoryPath)) {
		if (it.status().type() != std::experimental::filesystem::file_type::directory) {
			if (it.path().filename() == filename) {
				std::cout << "Loaded " << it.path().filename() << std::endl;
				return _texturesRegistry.load(std::move(id.replace_extension("").filename()), std::move(it.path()));
			}
		}
    	}
    	return _texturesRegistry.load(std::move(id.replace_extension("").filename()), filename);
    }

    void loadAllTexturesInDirectory(const std::experimental::filesystem::path &filename) {
	    for (auto &it : std::experimental::filesystem::recursive_directory_iterator(_resourceDirectoryPath)) {
		    if (it.status().type() == std::experimental::filesystem::file_type::directory && it.path().filename() == filename) {
			    for (auto &sub : std::experimental::filesystem::recursive_directory_iterator(it.path())) {
			    	if (sub.status().type() != std::experimental::filesystem::file_type::directory)
			    		loadTexture(std::move(sub.path().filename()));
			    }
			    return;
		    }
	    }
    }

    sf::Texture &getTexture(const std::string &id) noexcept {
    	return _texturesRegistry.get(id);
    }

    void remove(const std::string &id) {
	_texturesRegistry.remove(id);
    }

    AnimationState &loadAnimation(const std::experimental::filesystem::path &filename) {
    	/*
    	 * Search for the animation directory
    	 */
    	for (auto &it : std::experimental::filesystem::recursive_directory_iterator(_resourceDirectoryPath)) {
		if (it.status().type() == std::experimental::filesystem::file_type::directory && it.path().filename() == filename) {
			for (auto sub : std::experimental::filesystem::directory_iterator(it.path())) {
				loadTexture(sub.path().filename());
				std::experimental::filesystem::path id = sub.path();
				_animations[filename.string()].getAnimations().push_back(id.filename().replace_extension(""));
			}
			std::sort(_animations[filename.string()].getAnimations().begin(), _animations[filename.string()].getAnimations().end());
			break ;
		}
    	}
    	return _animations[filename.string()];
    }

    AnimationState &getAnimation(const std::string &id) noexcept {
    	return _animations[id];
    }

private:
    TexturesRegistry _texturesRegistry;

    std::experimental::filesystem::path _resourceDirectoryPath;
    std::unordered_map<std::string, AnimationState> _animations;
};
