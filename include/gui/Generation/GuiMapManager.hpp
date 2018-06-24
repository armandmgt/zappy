/*
** EPITECH PROJECT, 2018
** Project
** File description:
** Generation
*/

#pragma once

#include <functional>
#include <random>
#include <vector>

class GuiMapManager {
public:
	GuiMapManager(int width, int height, size_t percentage, size_t step);
	void dump();
	std::vector<std::vector<int>> getMap();

private:
	size_t countNeighbour(int y, int x);
	void doStep();
	void initMap();
	int _width;
	int _height;
	size_t _percentage;
	size_t _numberStep;
	std::vector<std::vector<int>> _gMap;
};