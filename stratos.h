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

#endif
