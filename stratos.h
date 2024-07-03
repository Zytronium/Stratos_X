#ifndef STRATOS_H
#define STRATOS_H

enum ShipClass {
	StratosX,
	Interceptor,
	Fighter,
	Corvette,
	Frigate,
	Destroyer,
	Cruiser,
	PlayerStation,
	CoreSec_Battleship,
	Null
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


void setWave(Ship_t destWave[50], ...);

Ship_t *initWave(Ship_t waveShips[50], int wave);

Ship_t createShip(enum ShipClass class);

#endif
