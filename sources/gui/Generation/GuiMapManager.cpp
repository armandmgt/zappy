/*
** EPITECH PROJECT, 2018
** Project
** File description:
** Generation
*/

#include <cmath>
#include <ctime>
#include <iostream>
#include <thread>
#include "GuiMapManager.hpp"

GuiMapManager::GuiMapManager(int width, int height, size_t percentage, size_t step) :
	_width(width), _height(height), _percentage(percentage), _numberStep(step),
	_gMap(_height, std::vector<int>(_width, 0))
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	initMap();
}

//size_t GuiMapManager::countTopLeftCorner(int y, int x)
//{
//	size_t  count = 0;
//
//	if (x - 1 >= 0 && )
//}

size_t GuiMapManager::countNeighbour(int y, int x)
{
	size_t count = 0;

	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			int neighbourX = x + i;
			int neighbourY = y + j;
			if (i == 0 && j == 0)
				continue;
			else if( neighbourX < 0 || neighbourY < 0 ||
				neighbourX >= static_cast<int>(_gMap.size()) ||
				neighbourY >= static_cast<int>(_gMap[0].size())) {
				count = count + 1;
			} else if (_gMap[neighbourX][neighbourY])
				count = count + 1;
		}
	}
	return count;
}

void GuiMapManager::initMap()
{
	for (int x = 0; x < _width; x++) {
		for (int y = 0; y < _height; y++) {
			if (static_cast<size_t>((rand() % 100)) < _percentage)
				_gMap[x][y] = 1;
		}
	}
	for (size_t i = 0; i < _numberStep; i++)
		doStep();
}

void GuiMapManager::dump() {
	for (auto &it : _gMap) {
		for (auto &it2 : it) {
			std::cout << it2 << " ";
		}
		std::cout << std::endl;
	}
}

void GuiMapManager::doStep()
{
	std::vector<std::vector<int>> tmp = std::vector(_height, std::vector<int>(_width, 0));

	for (int x = 0; x < static_cast<int>(_gMap.size()); x++) {
		for (int y = 0; y < static_cast<int>(_gMap[0].size()); y++){
			size_t nbs = countNeighbour(x, y);
			if (_gMap[x][y]) {
				if (nbs < 3)
					tmp[x][y] = 0;
				else
					tmp[x][y] = 1;
			} else // 4 Is the number we need around a cell to create another
				tmp[x][y] = nbs > 3;
		}
	}
	_gMap = tmp;
}

std::vector<std::vector<int>> GuiMapManager::getMap()
{
	return _gMap;
}

