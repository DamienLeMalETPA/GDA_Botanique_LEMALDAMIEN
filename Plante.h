#ifndef PlANTE_H
#define PlANTE_H

#include <string>

class Plant{
	protected:
		std::string _plantName;
		int _value;
		int _baseValue = _value;
		int _fed;
		int _growth;//scale from 0 to 100
		float _health;//scale from -1 to 1
		float _hydration;//scale from -1 to 1

	public:

		int virtual grow();
		void virtual feed();
		void virtual cut();
		void virtual water();
		int virtual getValue();

		void display();
		void displayName(int i);

		Plant(std::string plantName, int value, int health, int hydration);
};
#endif