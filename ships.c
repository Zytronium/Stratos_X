#include <stdarg.h>
#include <stdio.h>
#include <malloc.h>
#include "ships.h"

/**
 * Creates a ship with the default starting properties for the given class.
 *
 * @param class The class of ship to create. This determines the default stats.
 *
 * @return The newly created ship.
 */
Ship_t createShip(enum ShipClass class)
{
	switch (class)
	{
		case StratosX: /* Player's Ship. All other types (except Player Station and Null) are enemies */
			return (Ship_t) {StratosX, 800, 750, 800, 750, 160, 45};

		case Interceptor:
			return (Ship_t) {Interceptor, 75, 125, 75, 125, 170, 15};

		case Fighter:
			return (Ship_t) {Fighter, 170, 50, 170, 50, 135, 20};

		case Corvette:
			return (Ship_t) {Corvette, 300, 350, 300, 350, 115, 35};

		case Frigate:
			return (Ship_t) {Frigate, 450, 400, 450, 400, 90, 45};

		case Destroyer:
			return (Ship_t) {Destroyer, 950, 725, 950, 725, 80, 60};

		case Cruiser:
			return (Ship_t) {Cruiser, 1450, 1100, 1450, 1100, 45, 80};

		case CoreSec_Battleship:
			return (Ship_t) {CoreSec_Battleship, 12000, 5000, 12000, 5000, 10, 110};

		case PlayerStation: /* Non-Null Placeholder */
			return (PLACEHOLDER_SHIP);

		default: /* Null or any other type I may add in the future and forget to add a case for */
			return (NULL_SHIP);
	}
}

/**
 * Initializes (NOT initiates) a wave. Creates all the ships that will be
 * in this wave. Slightly randomizes each wave except the final boss.
 *
 * @param waveShips The array of ships to initialize.
 * @param wave The wave number. 6 is the final boss.
 */
void initWave(Wave_t waveShips, int wave)
{
	int i;

	switch (wave)
	{
		case 1:
			for (i = 0; i < 8; i++)
			{
				// TODO: init waveShips for wave 1.
			}
			break;

		case 2:
			for (i = 0; i < 16; i++)
			{
				// TODO: init waveShips for wave 2
			}
			break;

		case 3:
			for (i = 0; i < 34; i++)
			{
				// TODO: init waveShips for wave 3
			}
			break;

		case 4:
			for (i = 0; i < 42; i++)
			{
				// TODO: init waveShips for wave 4
			}
			break;

		case 5:
			for (i = 0; i < 27; i++)
			{
				// TODO: init waveShips for wave 5
			}
			break;

		case 6:
			setWave(waveShips, createShip(Cruiser), createShip(Cruiser),
					createShip(Cruiser), createShip(Destroyer),
					createShip(Destroyer), createShip(CoreSec_Battleship),
					NULL_SHIP);
			break;

		default:
			fprintf(stderr, "ERROR: wave %d does not exist.\n", wave);
			break;
	}
}

/**
 * Converts the name of a ship's class to a string.
 *
 * @param class The ship class convert to a string.
 *
 * @return The name of a ship's class as a string.
 */
char *classToStr(enum ShipClass class)
{
	switch (class)
	{
		case Interceptor:
			return ("Interceptor");

		case Fighter:
			return ("Fighter");

		case Corvette:
			return ("Corvette");

		case Frigate:
			return ("Frigate");

		case Destroyer:
			return ("Destroyer");

		case Cruiser:
			return ("Cruiser");

		case CoreSec_Battleship:
			return ("CoreSec Battleship");

		case StratosX:
			return ("Stratos-X");

		case PlayerStation:
			return ("Player Station");

		case Null:
			return (NULL);

		default:
			fprintf(stderr, "ERROR: This ship class enum is unknown.\n");
			return ("Unknown");
	}
}

/**
 * Initializes or overwrites an array, assumed to be a wave, of ships.
 * Exits the program on malloc failure.
 *
 * @param destWave The array of ships that we are setting.
 * @param ... Ships that belong in destWave.
 */
void setWave(Wave_t destWave, ...)
{
	Wave_t *tempNode; /* new node to create */
	Wave_t *head = &destWave; /* first node of wave list */
	va_list ships; /* all args after destWave, assumed to be of type Ship_t */
	Ship_t ship = PLACEHOLDER_SHIP; /* Note:
 * Initialized here so that it can start the loop.
 * An uninitialized var would crash the program.
 * Not NULL_SHIP because loop would never run.
 * Not va_arg because 1: va_start hasn't been called yet,
 * and 2: the first arg would be skipped.
 */

	va_start(ships, destWave);

	while (ship.class != Null) /* iterates through all ships given */
	{
		/*
		 * NOTE: The issue with this is that it reallocates tempNode each time,
		 * so it's really just replacing the last ship with this one on each
		 * iteration. The solution, which I will implement after this commit,
		 * should be to simply do this recursively.
		 * Good thing I never deleted add_node() earlier.
		 */
		ship = va_arg(ships, Ship_t); /* sets ship to next ship in ships list*/
		tempNode = malloc(sizeof(Wave_t)); /* allocates memory for new node */

		if (tempNode == NULL) /* if mem alloc fails,... */
			exit(EXIT_FAILURE); /* ... then exits program. */

		printShip(ship); /* prints the stats of this ship */

		tempNode->ship = ship; /* sets new node ship to this ship */
		tempNode->next = NULL; /* initializes next node ptr to NULL (it doesn't exist yet) */

		if (head[0].ship.class != Null) /* if the wave list's first ship is not NULL_SHIP, ... */
			tail_node(&destWave)->next = tempNode; /* find and set tail node to the newly created node */
		else /* or, if it is NULL_SHIP (meaning the list is empty), ... */
			head[0] = *tempNode; /* set the head node to newly created node. */ /* TODO: should tempNode be freed after this? */
	}

	va_end(ships);
}

/**
 * Adds a node to the end of a Wave_t list
 * Alternative method that I may not use.
 * May delete later.
 *
 * @param head the pointer to the head of the Wave_t list
 * @param ship the ship to add to the list
 *
 * @return pointer to the new node, or NULL on failure.
 */
Wave_t *add_node(Wave_t **head, Ship_t ship)
{
	Wave_t *tempNode = malloc(sizeof(Wave_t));

	if (tempNode == NULL)
		return (NULL);

	tempNode->ship = ship;
	tempNode->next = NULL;

	if (*head != NULL)
		tail_node(*head)->next = tempNode;
	else
		*head = tempNode;

	return (tempNode);
}

/**
 * Finds the last (non-NULL) node of a list
 *
 * @param head: the head or starting node of the search
 *
 * @return pointer to the last node of a list
 */
Wave_t *tail_node(Wave_t *head)
{
	if (head == NULL)
		return (NULL);

	if (head->next == NULL || head->next->ship.class == Null)
		return (head);

	return (tail_node(head->next));
}

/**
 * Prints the properties of a ship.
 *
 * @param ship The ship to print the properties of.
 */
void printShip(Ship_t ship)
{
	int i;

	for (i = 0; i < 6; i++)
	{
		switch (i)
		{
			case 0:
				printf("Class: %s\n", classToStr(ship.class));
				break;

			case 1:
				printf("Hull HP: %.1f/%.1f max\n", ship.hullHp, ship.maxHull);
				break;

			case 2:
				printf("Shields HP: %.1f/%.1f max\n", ship.shieldsHp, ship.maxShields);
				break;

			case 3:
				printf("Max Speed: %.0f\n", ship.speed);
				break;

			case 4:
				printf("DPS: %d\n", ship.dps);
				break;

			default:
				putchar('\n');
				break;
		}
	}
}

/**
 * Prints the properties of every ship in a given wave.
 *
 * @param wave The wave to print the properties of.
 */
void printWave(Wave_t *wave)
{
	Wave_t *tempNode = wave;

	printf("-------\n");

	while (tempNode->ship.class != Null)
	{
		printShip(tempNode->ship);
		tempNode = tempNode->next;
	}
}

