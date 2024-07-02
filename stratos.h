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
	float maxHull;
	float maxShields;
	float hullHp;
	float shieldsHp;
	int dps;

} Ship_t;


void setWave(Ship_t destWave[50], Ship_t srcWave[50]);

Ship_t *initWave(int wave);

Ship_t createShip(enum ShipClass class);

#endif
