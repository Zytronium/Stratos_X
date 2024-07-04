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

/**
 * Creates a thread and plays a sound effect on that thread, allowing any code
 * following a call to this function to run at the same time without waiting
 * for the sound effect to end.
 *
 * @param alarmEffect void pointer to a sound_effect_t that contains 2 properties:\n\n\n
 * alarmEffect.effect: The sound effect to play.\n\n
 * alarmEffect.isPlayingPtr: A pointer to an int value that lets the sound
 * effect know when to stop playing. Use NULL if you know this wont be used.
 *
 * @example @code
 * int alarm1playing = 1;
 * sound_effect_t alarm = {Alarm1, &alarm1playing};
 * pthread_t thread;
 *
 * pthread_create(&thread, NULL, soundThread, &alarm);
 *
 * // Do something while alarm plays
 *
 * pthread_join(thread, NULL);
 * @endcode
 *
 * @return NULL
 */
void *soundThread(void *alarmEffect)
{
	sound_effect_t alarm = *(sound_effect_t *) alarmEffect;

	soundEffect(alarm.effect, alarm.isPlayingPtr);

	return (NULL);
}
