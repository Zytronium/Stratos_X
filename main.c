#include <stdio.h>

enum Ship {
	StratosX,
	Interceptor,
	Fighter,
	Corvette,
	Frigate,
	Destroyer,
	Cruiser,
	PlayerStation,
	CoreSec_Battleship
};

int main(void)
{
	float playerShields = 100, playerHull = 100;
	enum Ship playerShip = StratosX, wave1Ships[9] = { }, wave2Ships[21] = { },
			wave3Ships[36] = { }, wave4ships[46] = { }, wave5Ships[20] = { },
			bossFight = CoreSec_Battleship;


	return (0);
}
