#include "stratos.h"
#include <stdarg.h>

/**
 * Entry point.
 *
 * @return zero: success.
 */
int main(void)
{
	Ship_t playerShip = createShip(StratosX);
	Ship_t waves[6][50];

	initWave(waves[0], 1);
	initWave(waves[1], 2);
	initWave(waves[2], 3);
	initWave(waves[3], 4);
	initWave(waves[4], 5);
	initWave(waves[5], 6);

	return (0);
}

/**
 * Creates a ship with the default starting properties for the given class.
 *
 * @param class The class of ship to create. This determines the default stats.
 *
 * @return The newly created ship.
 */
Ship_t createShip(enum ShipClass class)
{
	switch (class) {
		case StratosX: /* Player's Ship. All other types (except Player Station and Null) are enemies */
			return (Ship_t) { StratosX, 800, 750, 800, 750, 160, 45 };

		case Interceptor:
			return (Ship_t) { Interceptor, 75, 125, 75, 125, 170, 15 };

		case Fighter:
			return (Ship_t) { Fighter, 170, 50, 170, 50, 135, 20 };

		case Corvette:
			return (Ship_t) { Corvette, 300, 350, 300, 350, 115, 35 };

		case Frigate:
			return (Ship_t) { Frigate, 450, 400, 450, 400, 90, 45 };

		case Destroyer:
			return (Ship_t) { Destroyer, 950, 725, 950, 725, 80, 60 };

		case Cruiser:
			return (Ship_t) { Cruiser, 1450, 1100, 1450, 1100, 45, 80 };

		case CoreSec_Battleship:
			return (Ship_t) { CoreSec_Battleship, 12000, 5000, 12000, 5000, 10, 110 };

		default: /* Player Station, Null, or any other type I may add in the future and forget to add a case for */
			return NULL_SHIP;
	}
}

/**
 * Initializes (NOT initiates) a wave. Creates all the ships that will be
 * in this wave. Slightly randomizes each wave except the final boss.
 *
 * @param waveShips The array of ships to initialize.
 * @param wave The wave number. 6 is the final boss.
 */
void initWave(Ship_t waveShips[50], int wave)
{
	int i;

	switch (wave) {
		case 1:
			for (i = 0; i < 8; i++)
			{
//				TODO: init waveShips for wave 1.
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
			setWave(waveShips, createShip(Cruiser), createShip(Cruiser), createShip(Cruiser), createShip(Destroyer), createShip(Destroyer), createShip(CoreSec_Battleship), NULL_SHIP);
			break;

		default:
			break;

	}
}

/**
 * Initializes or overwrites an array, assumed to be a wave, of ships.
 *
 * @param destWave The array of ships that we are setting.
 * @param ... Ships that belong in destWave.
 */
void setWave(Ship_t destWave[50], ...)
{
	va_list ships;
	int i = 0;
	Ship_t ship;

	va_start(ships, destWave);
	while (i < 50)
	{
		ship = va_arg(ships, Ship_t);
		if (ship.class == Null)
			break;

		destWave[i] = ship;
		i++;
	}
	va_end(ships);

	// Set the remaining elements of the array to NULL
	while (i < 50)
	{
		destWave[i] = NULL_SHIP;
		i++;
	}
}
