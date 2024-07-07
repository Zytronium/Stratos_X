#ifndef SHIPS_H
#define SHIPS_H

/* class of a Ship_t ship */
enum ShipClass {
	Null, /* Null terminator */
	StratosX, /* Player Ship */
	Interceptor,
	Fighter,
	Corvette,
	Frigate,
	Destroyer,
	Cruiser,
	CoreSec_Battleship, /* Final boss */
	PlayerStation /* Placeholder with a joke name */
};
/* 					^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^
 * Note: I may add a ShipClass for destroyed ships. This will depend on
 * what I do when I get to developing the part of the game that handles
 * destroyed ships. I can either check if a ship's hullHP is 0, add a
 * "isDestroyed" property and check that, or change the ship to Destroyed"
 * class. Most likely, it will be one of the first 2 options.
 */

/* properties/statistics of a ship entity  */
typedef struct Ship {
	enum ShipClass class;
	double maxHull;
	double maxShields;
	double hullHp;
	double shieldsHp;
	double speed; /* max speed, not current */
	int dps; /* damage per second */
} Ship_t;

/* Singly linked list of ship nodes. */
typedef struct Wave_s
{
	Ship_t ship; /* this ship */
	struct Wave_s *next; /* pointer to next node in list */
} Wave_t;

void setWave(Wave_t *destWave, ...);

void initWave(Wave_t *waveShips, int wave);

Wave_t *add_node(Wave_t **head, Ship_t ship);

Wave_t *tail_node(Wave_t *head);

Ship_t createShip(enum ShipClass class);

char *classToStr(enum ShipClass class);

void printShip(Ship_t ship);

Wave_t *printWave(Wave_t *wave);

#endif /* SHIPS_H */

#ifndef NULL_SHIP
#define NULL_SHIP (Ship_t) {Null, 0, 0, 0, 0, 0, 0}
/* Null Terminator ship */
#endif /* NULL_SHIP */

#ifndef PLACEHOLDER_SHIP
#define PLACEHOLDER_SHIP (Ship_t) {PlayerStation, 0, 0, 0, 0, 0, 0}
/*
 * Placeholder for when you need to initialize a Ship_t but can't
 * init as a null and don't want to init as an actual ship type
 */
#endif /* PLACEHOLDER_SHIP */
