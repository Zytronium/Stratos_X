#include <unistd.h>
#include <stdio.h>
#include "sleep.h"

/**
 * Sleeps for a given amount of time in a given unit of time.
 * Does not support nanoseconds because I was too lazy to bother
 * learning how nanosleep works.
 *
 * @param time how long to sleep for in the given unit of time
 * @param unit Unit of time that time is measured in.\n
 * Usec and Microsec are
 * microseconds, or 1/1,000,000th of a second, Millisec is milliseconds,
 * or 1/1,000th of a second, Sec is seconds, and Min is minutes.
 *
 * @return 0 on success, -1 on error if using Usec, Microsec, or Millisec, or
 * number of seconds left to sleep if interrupted while sleeping using Seconds
 */
int customSleep(time_t time, enum TimeUnit unit)
{
	switch (unit)
	{
		case Usec:
			return usleep(time);

		case Microsec:
			return usleep(time);

		case Millisec:
			if (time < 1000)
				return usleep(time * 1000);
			else
			{
						sleep(time / 1000);
				return usleep(time - ((time / 1000) * 1000));
			}

		case Sec:
			return sleep(time);

		case Min:
			return sleep(time * 60);
	}

	return (0);
}
