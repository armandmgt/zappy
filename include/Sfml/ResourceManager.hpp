//
// EPITECH PROJECT, 2018
// Zappy
// File description:
// ResourcesManager
//

#pragma once

#include <iostream>
#include <filesystem>
#include <unordered_map>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

namespace sfml {
    template<typename Resource, typename Identifier>
    class ResourceHolder {
    public:
	ResourceHolder(const ResourceHolder &) = delete;

	ResourceHolder &operator=(const ResourceHolder &) = delete;

	ResourceHolder() noexcept
	{
	}

	template<typename ...Args>
	Resource &load(const Identifier &id, Args &&...args)
	{
		Resource res;

		if (!res.loadFromFile(std::forward<Args>(args)...)) {
			throw std::runtime_error("Impossible to load file");
		}

		if (!_resourcesRegistry.emplace(id, std::move(res)).second) {
			throw std::runtime_error("Impossible to emplace in map. Object already exists?");
		}

		return _resourcesRegistry[id];
	}

	void remove(const Identifier &id) noexcept
	{
		if (_resourcesRegistry.count(id) == 1) {
			_resourcesRegistry.erase(id);
		}
	}

	const Resource &get(const Identifier &id) const
	{
		return _resourcesRegistry.at(id);
	}

	Resource &get(const Identifier &id)
	{
		return _resourcesRegistry.at(id);
	}

	template<typename ...Args>
	Resource &getOrLoad(const Identifier &id, Args &&...args)
	{
		if (_resourcesRegistry.count(id) == 0) {
			return load(id, std::forward<Args>(args)...);
		}
		return get(id);
	}

	void clear() noexcept
	{
		_resourcesRegistry.clear();
	}

    private:
	std::unordered_map<Identifier, Resource> _resourcesRegistry;
    };

    template<typename ResourceIdentifier>
    class ResourceManager {
    public:
	using TTexture = sf::Texture;

    private:
	using TexturesRegistry = ResourceHolder<sf::Texture, ResourceIdentifier>;

    public:
	explicit ResourceManager(std::filesystem::path resourceDirectoryPath = std::filesystem::current_path()) noexcept : _resourceDirectoryPath(std::move(resourceDirectoryPath)) = default;
	{

	}

    private:
	template<typename Resource, typename Registry>
	Resource &_load(Registry &registry, const std::string &resourceTypePath, const std::filesystem::path &&filename) noexcept
	{
		ResourceIdentifier id = std::filesystem::path(filename).replace_extension("").string();
		return registry.load(id, std::filesystem::path(_resourceDirectoryPath / resourceTypePath / filename).string());
	}

	template<typename Registry>
	void _remove(const ResourceIdentifier &id, Registry &registry) noexcept
	{
		registry.remove(id);
	}

    protected:

	TTexture &loadTexture(std::filesystem::path &&filename)
	{
		return _load<TTexture>(_texturesRegistry, "textures", std::move(filename));
	}

	void unloadTexture(const ResourceIdentifier &id) noexcept
	{
		_remove(id, _texturesRegistry);
	}

	TTexture &getTexture(const ResourceIdentifier &id)
	{
		return _texturesRegistry.get(id);
	}

    private:
	std::filesystem::path _resourceDirectoryPath;
	TexturesRegistry _texturesRegistry;
    };
}

namespace resource {
    template<template<typename> typename ResourceManagerImpl, typename ResourceIdentifier = std::string>
    class ResourceManager : private ResourceManagerImpl<ResourceIdentifier> {
    public:
	using TResourceManager = ResourceManagerImpl<ResourceIdentifier>;
	using TTexture = typename TResourceManager::TTexture;

    public:
	TTexture &loadTexture(std::filesystem::path filename)
	{
		return TResourceManager::loadTexture(std::move(filename));
	}

	void unloadTexture(const ResourceIdentifier &id)
	{
		TResourceManager::unloadTexture(id);
	}
    };
}
