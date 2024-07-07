#ifndef SLEEP_H
#define SLEEP_H

#include <stdio.h>

enum TimeUnit {
	Usec,		/* Microseconds - 1/1,000,000th of a second 				*/
	Microsec,	/* Microseconds - 1/1,000,000th of a second 				*/
	Millisec,	/* Milliseconds - 1/1,000th of a second 					*/
	Sec,		/* Seconds - 1mil microseconds, 1k milliseconds, 1/60th of a minute (duh) */
	Min			/* Minutes - 60 seconds, 1/60th of an hour.	(duh)			*/
};

int customSleep(time_t time, enum TimeUnit unit);

#endif /* SLEEP_H */
