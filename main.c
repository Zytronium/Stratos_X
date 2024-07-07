#include "stratos.h"
#include "ships.h"
#include "sounds.h"
#include "sleep.h"
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

/**
 * Entry point.
 *
 * @return 0: success.
 */
int main(void)
{
	Ship_t playerShip = createShip(StratosX);
	Wave_t waves[6];
	int i, alarm1playing = true;
	sound_effect_t alarm = {Alarm3, &alarm1playing};
	pthread_t thread;

	pthread_create(&thread, NULL, soundThread, &alarm);
	sleep(3);
	alarm1playing = false;
	// updateDisplay(32, 24); /* TODO: This needs to be on its own thread */

	for (i = 0; i < 6; i++)
		initWave(waves[i], i + 1);

	printWave(waves[5]);

	pthread_join(thread, NULL);

	sleep(4);

	return (0);
}

/**
 * prints the display screen with a neat frame around it. This is recursive,
 * so it should only be called once.
 *
 * @param width what do you think
 * @param height  w\n h\n a\n t\n  \n d\n o\n  \n y\n o\n u\n  \n t\n h\n i\n n\n k
 */
void updateDisplay(int width, int height)
{
	int i, j, printedW = 0, printedH = 0, printed = 0;
	char cornerBL = 200, cornerTL = 201, edgeTB = 205, cornerTR = 187, edgeLR = 186, cornerBR = 188;
	char display[(((width * 2) + 2) * 2) + (height * 2) + ((width * 2) * height) + height + 3];

	display[printed] = cornerTL;
	printed++;
	for (i = 0; i < width * 2; i++)
	{
		display[printed] = edgeTB;
		printed++;
	}
	display[printed] = cornerTR;
	printed++;
	display[printed] = '\n';
	printed++;
	for (i = 0; i < height; i++)
	{
		display[printed] = edgeLR;
		printed++;
		for (j = 0; j < width * 2; j++)
		{
			display[printed] = ' ';
			printed++;
			if (!i)
				printedW++;
		}
		display[printed] = edgeLR;
		printed++;
		printedH++;
		display[printed] = '\n';
		printed++;
	}
	display[printed] = cornerBL;
	printed++;
	for (i = 0; i < width * 2; i++)
	{
		display[printed] = edgeTB;
		printed++;
	}
	display[printed] = cornerBR;
	printed++;
	display[printed] = '\n';
	printed++;
	display[printed] = '\0';

	printf("%s", display);
	printf("width: %d chars; height: %d chars; display pixels: %d; "
		   "display size (including frame and newlines): %llu.\n",
		   printedW, printedH, printed - height - 2, sizeof(display) - 1);
	customSleep(500, Millisec);
	system("cls");
	updateDisplay(width, height);
}
