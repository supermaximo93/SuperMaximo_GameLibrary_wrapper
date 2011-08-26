/*
 * Sound-C.h
 *
 *  Created on: 26 Aug 2011
 *      Author: Max Foster
 */

#ifndef SOUNDC_H_
#define SOUNDC_H_

#ifdef __cplusplus

class Sound;
extern "C" {

#else

typedef struct Sound Sound;

#endif

Sound * soundNew(const char * newName, const char * fileName);
void soundDelete(Sound * sound);
const char * soundName(Sound * sound);
void soundSetVolume(Sound * sound, int percentage, int relative);
int soundVolume(Sound * sound);
int soundPlay(Sound * sound, int newVolume, int channel);
void soundStop(Sound * sound);
void soundSetSoundPosition(Sound * sound, int angle, int distance);

void allocateSoundChannels(unsigned channels);

#ifdef __cplusplus
}
#endif

#endif /* SOUNDC_H_ */
