#ifndef Botanist_CPP
#define Botanist_CPP

#include <iostream>
#include <vector>
#include "Botaniste.h"

void Botanist::sleep() {
	int o;
	for (int i = 0; i < _garden.size(); i++) {	
		o = _garden[i].grow();
		_day += 1;
		if (o == 0) {
			_garden.erase(_garden.begin() + i);
		}
	}
}

void Botanist::feeding(int i) {
	_garden[i].feed();
}
void Botanist::cutting(int i) {
	_garden[i].cut();
}
void Botanist::watering(int i) {
	_garden[i].water();
}
void Botanist::getInfos(int i) {
	_garden[i].display();
}

void Botanist::sell(int i) {
	_money += _garden[i].getValue();
	_garden.erase(_garden.begin() + i);
}

int Botanist::getGardenSize() {
	int  p;
	p = _garden.size();
	return p;
}


void Botanist::displayDay(){
	std::cout << "Jour " << _day << std::endl; 
}

void Botanist::displayGarden(){
	for (int i = 0; i < _garden.size(); i++) {	
		_garden[i].displayName(i+1);
	}
	std::cout << "[" << _garden.size() + 1 << "] Retour" << std::endl;
}

void Botanist::display() {
	std::cout << _playerName << " est un jardinier\n" 
              << _money << " euros\n Jardin :\nPlante n°1 :"
              << std::endl;
	_garden[0].display();
}

void Botanist::displayAction() {
	std::cout << "[1] Ajouter de l'engrais (possédé : " << _fertilizer 
			  << ")\n[2] Tailler\n[3] Arroser\n[4] Infos\n[5] Vendre\n[6] Retour" << std::endl;
}

Botanist::Botanist(std::string playerName, std::vector<Plant> garden) : _playerName(playerName), _garden(garden), _fertilizer(0){};

#endif