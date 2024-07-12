#include "extend_def.h"
#include <stdarg.h>
#include <stdio.h>
#include <malloc.h>
#include "ships.h"

/**
 * Creates a ship with the default starting properties for the given class.
 * Do I even need this anymore? I've replaced all this with macros.
 *
 * @param class The class of ship to create. This determines the default stats.
 *
 * @return The newly created ship.
 */
Ship_t newShip(enum ShipClass class)
{
	switch (class)
	{
		case StratosX: /* Player's Ship. All other types (except Player Station and Null) are enemies */
			return (STRATOS_X_DEFAULT);

		case Interceptor:
			return (INTERCEPTOR_SHIP_DEFAULT);

		case Fighter:
			return (FIGHTER_SHIP_DEFAULT);

		case Corvette:
			return (CORVETTE_SHIP_DEFAULT);

		case Frigate:
			return (FRIGATE_SHIP_DEFAULT);

		case Destroyer:
			return (DESTROYER_SHIP_DEFAULT);

		case Cruiser:
			return (CRUISER_SHIP_DEFAULT);

		case CoreSec_Battleship:
			return (BATTLESHIP_DEFAULT);

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
 * @param waveShips Pointer to the array of ships to initialize.
 * @param wave The wave number. 6 is the final boss.
 */
void initWave(Wave_t *waveShips, int wave)
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
			setWave(waveShips, BATTLESHIP_DEFAULT,
					CRUISER_SHIP_DEFAULT, CRUISER_SHIP_DEFAULT,
					CRUISER_SHIP_DEFAULT, DESTROYER_SHIP_DEFAULT,
					DESTROYER_SHIP_DEFAULT, NULL_SHIP);
			break;

		default:
			fprintf(stderr, "ERROR: wave %d does not exist.\n", wave);
			break;
	}
}

/**
 * Converts the name of a ship's class to a string.
 *
 * @param class The ship class to convert to a string.
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
 * Initializes or overwrites a Wave_t list of ships.
 * Exits the program on malloc failure.
 *
 * @param destWave Pointer to the Wave_t list of ships that we are setting.
 * @param ... Ships that belong in destWave.
 */
void setWave(Wave_t *destWave, ...)
{
	Wave_t *tempNode; /* new node to create */
	va_list ships; /* all args after destWave, assumed to be of type Ship_t */
	Ship_t ship = PLACEHOLDER_SHIP; /* New ship at each iteration in the loop */
	/* Note:
 	 * Initialized here so that it can start the loop.
 	 * An uninitialized var would crash the program.
 	 * Not NULL_SHIP because loop would never run.
 	 * Not va_arg because 1: va_start hasn't been called yet,
 	 * and 2: the first arg would be skipped.
 	 */

	va_start(ships, destWave);

	loop()													/* iterates through all ships given, adding them to the end of the list one at a time */
	{
		ship = va_arg(ships, Ship_t);						/* sets ship to next ship in ships list*/

		breakif(ship.class == Null);						/* stop the loop at the end of the va_list of ship */

		tempNode = malloc(sizeof(Wave_t));					/* allocates memory for new node */
		if (tempNode == NULL)								/* if mem alloc fails,... */
			 exit(EXIT_FAILURE);							/* ... then exits program. */

		tempNode->ship = ship; 								/* sets new node ship to this ship */
		tempNode->next = NULL; 								/* initializes next node ptr to NULL (next one doesn't exist yet), making this the tail node, for now. */

		if (destWave != NULL && destWave->ship.class != Null) /* if the wave list's first ship is not NULL_SHIP, ... */
			tail_node(destWave)->next = tempNode;			/* find and set tail node to the newly created node */
		else if (destWave == NULL) 							/* if the head is NULL ... */
		{
			destWave = malloc(sizeof(Wave_t));              /* allocate memory for head if it is NULL */
			if (destWave == NULL)							/* check if malloc failed */
				exit(EXIT_FAILURE);							/* exit program if malloc failed */

			*destWave = *tempNode;							/* clone the temp node into the head */
			free(tempNode);									/* free tempNode because it's no longer in use */
		}
		else 												/* or, if it is NULL_SHIP (meaning the list is empty), but not NULL (meaning we don't need to create/malloc it) ... */
			*destWave = *tempNode; 							/* set the head node to newly created node. */
	}

	va_end(ships);
}

/**
 * Adds a node to the end of a Wave_t list
 * Alternative method that I may not use.
 * May delete later.
 *
 * @param wave the pointer to the head of the Wave_t list
 * @param ship the ship to add to the list
 *
 * @return pointer to the new node, or NULL on failure.
 */
Wave_t *add_ship_to_wave(Wave_t **wave, Ship_t ship)
{
	Wave_t *tempNode = malloc(sizeof(Wave_t));

	if (tempNode == NULL)
		return (NULL);

	tempNode->ship = ship;
	tempNode->next = NULL;

	if (*wave != NULL)
		tail_node(*wave)->next = tempNode;
	else
		*wave = tempNode;

	return (tempNode);
}

/**
 * Finds the last (non-NULL) node of a Wave_t list
 *
 * @param head: the head or starting node of the search
 *
 * @return pointer to the last node of a Wave_t list
 */
Wave_t *tail_node(Wave_t *head)
{
	if (head != NULL)
	{
		while (head->next != NULL)
			head = head->next;

		return (head);
	}

	return (NULL);
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
 * @param wave Pointer to the wave to print the properties of.
 *
 * @return Pointer to the last node who's class is not Null,
 * or NULL if it encounters a NULl wave.
 */
Wave_t *printWave(Wave_t *wave)
{
	if (wave == NULL)
		return (NULL);

	printShip(wave->ship);

	if (wave->next != NULL && wave->next->ship.class == Null)
		return (wave);

	return (printWave(wave->next));
}
