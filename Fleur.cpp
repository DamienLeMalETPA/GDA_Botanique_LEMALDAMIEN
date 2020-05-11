#ifndef Flower_CPP
#define Flower_CPP

#include <iostream>
#include "Fleur.h"

int Flower::grow(){
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
	ttc = 10 * _fed - (10*hp + 10*hdo);
	if (ttc < 0) {
		return 0;
	}else{
		_growth += ttc;
		_fed = 1;
	}
	//day's end
	_health -= 0.7;
	_hydration -= 0.3;
	if (_growth > 100 && _growth < 125) {
		if (_value == _baseValue) {
			_value = _value * 2;
		}
	}else if (_growth > 100){
		return 0;
	}
	return 1;
}

Flower::Flower(std::string plantName, int value, int health, int hydration) : Plant(plantName, value, health, hydration) {}

#endif