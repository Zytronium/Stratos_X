#ifndef SOUNDS_H
#define SOUNDS_H

enum Sound {
	Alarm1,
	Alarm2,
	Alarm3,
	Alarm4,
	Alarm5,
	Alarm6,
	Beep1,
	Beep2
};

typedef struct Sound_Effect {
	enum Sound effect;
	int *isPlayingPtr;
} sound_effect_t;

void soundEffect(enum Sound effect, int *isPlayingPtr);

void *soundThread(void *alarmEffect);

#endif /* SOUNDS_H */
