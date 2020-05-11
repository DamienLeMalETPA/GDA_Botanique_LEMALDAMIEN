#ifndef Hungry_CPP
#define Hungry_CPP

#include <iostream>
#include "Carnivore.h"

void Hungry::eat(){
	if (_hunger <= 0) {
		_hunger = 1;
	}else{
		std::cout << "Pas faim :/\n" << std::endl;
	}
}

void Hungry::display(){
	std::string txt;
	if (_hunger <= 0) {
		txt = "A faim";
	}else{
		txt = "Mange";
	}
	std::cout << "-----[ " << _plantName << " ]-----\n" 
              << "Valeur : " << _value << "\n"
			  << "Croissance : " << _growth << "%\n"
			  << "Santé : " << _health << "\n"
			  << "Hydratation : " << _hydration << "\n"
			  << "Humeur :" << txt
			  << std::endl;
}

int Hungry::grow(){
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
	_hunger -= 0.15;
	return 1;
}

Hungry::Hungry(std::string plantName, int value, int health, int hydration, int hunger) : Plant(plantName, value, health, hydration), _hunger(hunger) {}

#endif