#include "sounds.h"
#include <unistd.h>
#include <windows.h>
#include <stdio.h>

/**
 * Plays a sound effect using the windows Beep() function
 * currently Sound effects in enum Sound are placeholders.
 * This can either play a single beep, or a series of beeps,
 * like a song or an alarm.
 *
 * @param effect Which effect to play.
 * @param isPlaying pointer to a integer boolean that determines if the alarm
 * is playing. When the value this points to is 0, the sound effect ends, if
 * it is an effect that uses this parameter. You can safely use any value,
 * including NULL, if you know this value will not be used.
 */
void soundEffect(enum Sound effect, int *isPlayingPtr)
{
	int i;

	switch (effect)
	{
		case Alarm1:
			while (*isPlayingPtr)
			{
				Beep(260, 375);
				usleep(5000);
			}
			break;

		case Alarm2:
			while (*isPlayingPtr)
			{
				Beep(310, 410);
				usleep(40000);
			}
			break;

		case Alarm3:
			while (1)
			{
				if (*isPlayingPtr)
					Beep(550, 250);
				else
				{
					Beep(550, 2500);
					break;
				}
			}
			break;

		case Alarm4:
			// TODO
			break;

		case Alarm5:
			// TODO
			break;

		case Alarm6:
			// TODO
			break;

		case Beep1:
			// TODO
			break;

		case Beep2:
			// TODO
			break;

		default:
			// TODO
			break;
	}
}
