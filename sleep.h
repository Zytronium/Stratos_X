#ifndef SLEEP_H
#define SLEEP_H

enum TimeUnit {
	Usec,
	Microsec,
	Millisec,
	Sec,
	Min
};

int customSleep(time_t time, enum TimeUnit unit);

#endif
