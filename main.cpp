#include <iostream>
#include <string>
#include <vector>
#include "Plante.h"
#include "Botaniste.h"
#include "Fleur.h"
#include "Carnivore.h"

int main()
{
	Flower * test = new Flower("Jonquille", 15, 0, 0);
	Hungry * test1 = new Hungry("Dionee", 25, 0, 0, 0);
	
	std::string yourName;
	std::cout << "Botaniste ! Quel est votre nom ?"<<std::endl;
	std::cin >> yourName;


	//test->display();
	std::vector<Plant> vecteurJardin;
    vecteurJardin.push_back(*test);
    vecteurJardin.push_back(*test1);



	Botanist * moi = new Botanist(yourName, vecteurJardin);

	int sortie1 = 0;
	int sortie2 = 0;
	int sortie3 = 0;
	int choix;
	int choix2;
	int ok;
	int s;
	while (sortie1 == 0) {
		system("clear");
		sortie2 = 0;
		choix = 0;
		moi->displayDay();
		std::cout << "[1] Jardin\n[2] Magasin\n[3] Se Coucher"<<std::endl;
		std::cin >> choix;
		switch (choix) {
			case 1 :
				while (sortie2 == 0) {
					system("clear");
					sortie3 = 0;
					choix = 0;
					moi->displayGarden();
					std::cin >> choix;
					s = moi->getGardenSize();
					if (choix < s+1) {
						while (sortie3 == 0) {
							system("clear");
							choix2 = 0;
							moi->displayAction();
							std::cin >> choix2;
							switch (choix2) {
								case 1: moi->feeding(choix - 1); break;
								case 2: moi->cutting(choix - 1); break;
								case 3: moi->watering(choix - 1); break;
								case 4: moi->getInfos(choix - 1); break;
								case 5: moi->sell(choix - 1); sortie3 = 1; break;
								case 6: sortie3 = 1; break;
							}
							std::cout << "[Fait - Entrez n'importe quelle touche]" << std::endl;
							std::cin >> ok;
							system("clear");
						}
					}else{
						sortie2 = 1;
					}
				}
				break;
			case 2:
				break;
			case 3:
				moi->sleep();
				break;
		}
	}
	return 0;
}