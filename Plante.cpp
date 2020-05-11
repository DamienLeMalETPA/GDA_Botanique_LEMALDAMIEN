#ifndef Plant_CPP
#define Plant_CPP

#include <iostream>
#include <string>
#include "Plante.h"

int Plant::grow(){
	int ttc;
	int final;
	int hp;
	int hdo;
	if (_health < 0) {
		hp = _health * -1;
	}else{
		hp = _health;
	}
	if (_hydration < 0) {
		hdo = _hydration * -1;
	}else{
		hdo = _hydration;
	}
	ttc = 20 * _fed - (10*hp + 10*hdo);
	if (ttc < 0) {
		return 0;
	}else{
		_growth += ttc;
		_fed = 1;
	}
	//day's end
	_health -= 0.7;
	_hydration -= 0.3;
	return 1;
}
void Plant::feed(){
	if (_fed != 2) {
		_fed = 2;
	}else{
		std::cout << "Déjà fait aujourd'hui !" << std::endl;
	}
}
void Plant::cut(){
	_health += 0.6;
}
void Plant::water(){
	_hydration += 0.5;
}
int Plant::getValue(){
	return _value;
}

void Plant::display(){
	std::cout << "-----[ " << _plantName << " ]-----\n" 
              << "Valeur : " << _value << "\n"
			  << "Croissance : " << _growth << "%\n"
			  << "Santé : " << _health << "\n"
			  << "Hydratation : " << _hydration << "\n"
			  << std::endl;
}

void Plant::displayName(int i) {
	std::cout << "[" << i << "] " << _plantName << std::endl;
}

Plant::Plant(std::string plantName, int value, int health, int hydration) : _plantName(plantName), _value(value), _growth(0), _health(health), _hydration(hydration), _fed(1){}

#endif