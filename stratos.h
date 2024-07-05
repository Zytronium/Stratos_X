#ifndef STRATOS_H
#define STRATOS_H

enum ShipClass {
	Null,
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

typedef struct Ship {
	enum ShipClass class;
	double maxHull;
	double maxShields;
	double hullHp;
	double shieldsHp;
	double speed;
	int dps;

} Ship_t;

void updateDisplay(int width, int height);

void setWave(Ship_t destWave[50], ...);

void initWave(Ship_t waveShips[50], int wave);

Ship_t createShip(enum ShipClass class);

char *classToStr(enum ShipClass class);

void printShip(Ship_t ship);

#endif


#ifndef NULL_SHIP
#define NULL_SHIP (Ship_t) { Null, 0, 0, 0, 0, 0, 0 }

#endif
