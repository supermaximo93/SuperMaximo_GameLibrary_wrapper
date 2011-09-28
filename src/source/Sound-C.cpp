/*
 * Sound-C.cpp
 *
 *  Created on: 26 Aug 2011
 *      Author: Max Foster
 */

#include <SuperMaximo_GameLibrary/classes/Sound.h>

#include "../headers/Sound-C.h"

extern "C" {

Sound * soundNew(const char * newName, const char * fileName) {
	return (Sound*)(new SuperMaximo::Sound(newName, fileName));
}

void soundDelete(Sound * sound) {
	delete (SuperMaximo::Sound*)sound;
}

const char * soundName(Sound * sound) {
	return ((SuperMaximo::Sound*)sound)->name().c_str();
}

void soundSetVolume(Sound * sound, int percentage, int relative) {
	((SuperMaximo::Sound*)sound)->setVolume(percentage, relative);
}

int soundVolume(Sound * sound) {
	return ((SuperMaximo::Sound*)sound)->volume();
}

int soundPlay(Sound * sound, int newVolume, int channel) {
	return ((SuperMaximo::Sound*)sound)->play(newVolume, channel);
}

void soundStop(Sound * sound) {
	((SuperMaximo::Sound*)sound)->stop();
}

void soundSetSoundPosition(Sound * sound, int angle, int distance) {
	((SuperMaximo::Sound*)sound)->setSoundPosition(angle, distance);
}

void allocateSoundChannels(unsigned channels) {
	SuperMaximo::allocateSoundChannels(channels);
}

}
