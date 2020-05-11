#ifndef FLOWER_H
#define FLOWER_H

#include <string>
#include "Plante.h"

class Flower : public Plant {

	public:

		int grow();
		Flower(std::string plantName, int value, int health, int hydration);
};

#endif