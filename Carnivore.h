#ifndef HUNGRY_H
#define HUNGRY_H

#include <string>
#include "Plante.h"

class Hungry : public Plant {
	float _hunger;

	public:
		void eat();
		void display();
		int grow();

		Hungry(std::string plantName, int value, int health, int hydration, int hunger);
};

#endif