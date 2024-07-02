#include "stratos.h"
#include <stdio.h>

int main(void)
{
	Ship_t playerShip = { StratosX, 600, 600, 600, 600, 40 };
	Ship_t waves[6][50] = {
			{ Null },
			{ Null },
			{ Null },
			{ Null },
			{ Null },
			{ CoreSec_Battleship, Null }
	};

	return (0);
}

Ship_t *initWave(int wave)
{
	Ship_t waveShips[50];
	int i;

	switch (wave) {
		case 1:
			for (i = 0; i < 8; i++)
			{
//				TODO: init waveShips for wave 1
			}
			break;

		case 2:
			for (i = 0; i < 16; i++)
			{
//				TODO: init waveShips for wave 2
			}
			break;

		case 3:
			for (i = 0; i < 34; i++)
			{
//				TODO: init waveShips for wave 3
			}
			break;

		case 4:
			for (i = 0; i < 42; i++)
			{
//				TODO: init waveShips for wave 4
			}
			break;

		case 5:
			for (i = 0; i < 27; i++)
			{
//				TODO: init waveShips for wave 5
			}
			break;

		case 6:
			Ship_t shp[] = { createShip(Cruiser), createShip(Cruiser), createShip(Cruiser), createShip(Destroyer), createShip(Destroyer), createShip(CoreSec_Battleship), createShip(Null) };
			setWave(waveShips, shp);
			break;

		default:
			break;

	}

	return &(waveShips[0]);
}

Ship_t createShip(enum ShipClass class)
{
	switch (class) {
		case StratosX: /* Player's Ship. All other types (except Player Station and Null) are enemies */
			return (Ship_t) { StratosX, 800, 750, 800, 750, 45 };

		case Interceptor:
			return (Ship_t) { Interceptor, 75, 125, 75, 125, 15 };

		case Fighter:
			return (Ship_t) { Fighter, 170, 50, 170, 50, 20 };

		case Corvette:
			return (Ship_t) { Corvette, 300, 350, 300, 350, 35 };

		case Frigate:
			return (Ship_t) { Frigate, 450, 400, 450, 400, 45 };

		case Destroyer:
			return (Ship_t) { Destroyer, 950, 725, 950, 725, 60 };

		case Cruiser:
			return (Ship_t) { Cruiser, 1450, 1100, 1450, 1100, 80 };

		case CoreSec_Battleship:
			return (Ship_t) { CoreSec_Battleship, 12000, 5000, 12000, 5000, 105 };

		default: /* Player Station, Null, or any other type I may add in the future and forget to add a case for */
			return (Ship_t) { Null, 0, 0, 0, 0, 0 };
	}
}

void setWave(Ship_t destWave[50], Ship_t srcWave[50])
{
	int i;

	for (i = 0; i <= 51; ++i)
	{
		destWave[i] = srcWave[i];
	}
}
