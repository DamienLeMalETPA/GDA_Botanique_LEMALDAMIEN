#ifndef BOTANIST_H
#define BOTANIST_H

#include <string>
#include <vector>
#include "Plante.h"

class Botanist{
	private:
		int _day;
		int _money;
		int _fertilizer;
		std::string _playerName;
		std::vector<Plant> _garden;

	public:

		void sleep();
		void feeding(int i);
		void cutting(int i);
		void watering(int i);
		void getInfos(int i);
		void sell(int i);
		int getGardenSize();
		void displayDay();
		void displayGarden();
		void displayAction();
		void display();

		Botanist(std::string playerName, std::vector<Plant> garden);
};

#endif