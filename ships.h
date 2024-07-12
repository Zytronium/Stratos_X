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
 * Note: I didn't want to remove this pretty note (well just look at
 * the arrows above it, it looks so nice!) so I'll leave it here for
 * a few days, I suppose. I just really don't want to get rid of it.
 * For some reason, it looks better with 4 lines, so now we're good.
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

Ship_t newShip(enum ShipClass class);

char *classToStr(enum ShipClass class);

void printShip(Ship_t ship);

Wave_t *printWave(Wave_t *wave);

#ifndef STRATOS_X_DEFAULT
#define STRATOS_X_DEFAULT (Ship_t) {.class = StratosX, .maxHull = 850, .maxShields = 800, .hullHp = 850, .shieldsHp = 800, .speed = 240, .dps = 45}
/* default stats for a Stratos-X, the player's ship */
#endif /* STRATOS_X_DEFAULT */


#ifndef INTERCEPTOR_SHIP_DEFAULT
#define INTERCEPTOR_SHIP_DEFAULT (Ship_t) {.class = Interceptor, .maxHull = 75, .maxShields = 125, .hullHp = 75, .shieldsHp = 125, .speed = 250, .dps = 15}
/* default stats for an interceptor class ship */
#endif /*INTERCEPTOR_SHIP_DEFAULT*/


#ifndef FIGHTER_SHIP_DEFAULT
#define FIGHTER_SHIP_DEFAULT (Ship_t) {.class = Fighter, .maxHull = 170, .maxShields = 50, .hullHp = 170, .shieldsHp = 50, .speed = 215, .dps = 20}
/* default stats for a fighter class ship */
#endif /* FIGHTER_SHIP_DEFAULT */


#ifndef CORVETTE_SHIP_DEFAULT
#define CORVETTE_SHIP_DEFAULT (Ship_t) {.class = Corvette, .maxHull = 300, .maxShields = 350, .hullHp = 300, .shieldsHp = 350, .speed = 170, .dps = 35}
/* default stats for a corvette class ship */
#endif /* CORVETTE_SHIP_DEFAULT */


#ifndef FRIGATE_SHIP_DEFAULT
#define FRIGATE_SHIP_DEFAULT (Ship_t) {.class = Frigate, .maxHull = 450, .maxShields = 400, .hullHp = 450, .shieldsHp = 400, .speed = 135, .dps = 45}
/* default stats for a frigate class ship */
#endif /* FRIGATE_SHIP_DEFAULT */


#ifndef DESTROYER_SHIP_DEFAULT
#define DESTROYER_SHIP_DEFAULT (Ship_t) {.class = Destroyer, .maxHull = 950, .maxShields = 725, .hullHp = 950, .shieldsHp = 725, .speed = 105, .dps = 60}
/* default stats for a destroyer class ship */
#endif /* DESTROYER_SHIP_DEFAULT */


#ifndef CRUISER_SHIP_DEFAULT
#define CRUISER_SHIP_DEFAULT (Ship_t) {.class = Cruiser, .maxHull = 1450, .maxShields = 1100, .hullHp = 1450, .shieldsHp = 1100, .speed = 60, .dps = 80}
/* default stats for a cruiser class ship */
#endif /* CRUISER_SHIP_DEFAULT */


#ifndef BATTLESHIP_DEFAULT
#define BATTLESHIP_DEFAULT (Ship_t) {.class = CoreSec_Battleship, .maxHull = 12000, .maxShields = 5000, .hullHp = 12000, .shieldsHp = 5000, .speed = 15, .dps = 110}
/* default stats for the final boss, CoreSec Battleship */
#endif /* BATTLESHIP_DEFAULT */


#ifndef NULL_SHIP
#define NULL_SHIP (Ship_t) {Null, 0, 0, 0, 0, 0, 0}
/* Null Terminator ship */

#ifndef BLANK_WAVE
#define BLANK_WAVE (Wave_t) { .ship = NULL_SHIP, .next = NULL }
/* So you don't have to make a function to quickly initialize a blank wave */

#endif /* BLANK_WAVE */

#endif /* NULL_SHIP */


#ifndef PLACEHOLDER_SHIP
#define PLACEHOLDER_SHIP (Ship_t) {PlayerStation, 0, 0, 0, 0, 0, 0}
/*
 * Placeholder for when you need to initialize a Ship_t but can't
 * init as a null and don't want to init as an actual ship type
 */
#endif /* PLACEHOLDER_SHIP */

#endif /* SHIPS_H */
