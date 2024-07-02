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
			waveShips = { createShip(Cruiser), createShip(Cruiser), createShip(Cruiser), createShip(Destroyer), createShip(Destroyer), createShip(CoreSecBattleship), createShip(Null) };
			break;

	}

	return &(waveShips[0]);
}

void setWave(Ship_t destWave[50], Ship_t srcWave[50])
{
	int i;

	for (i = 0; i <= 51; ++i)
	{
		destWave[i] = srcWave[i];
	}
}

Ship_t createShip(enum ShipClass class)
{
	switch (class) {
		case StratosX:
			return (Ship_t) { class, 600, 600, 600, 600, 45 };

		case Interceptor:
			return (Ship_t) { class, 75, 125, 75, 125, 15 };

		case Fighter:
			return (Ship_t) { class, 170, 50, 170, 50, 20 };

		case Corvette:
			return (Ship_t) { class, 0, 0, 0, 0, 40 };

	}
}