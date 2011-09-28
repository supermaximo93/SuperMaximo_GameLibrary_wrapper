/*
 * Audio-C.cpp
 *
 *  Created on: 26 Aug 2011
 *      Author: Max Foster
 */

#include <SuperMaximo_GameLibrary/Audio.h>

#include "../headers/Audio-C.h"

extern "C" {

void initAudio(unsigned channels) {
	SuperMaximo::initAudio(channels);
}

void quitAudio() {
	SuperMaximo::quitAudio();
}

void soundPosition(int channel, int angle, int distance) {
	SuperMaximo::soundPosition(channel, angle, distance);
}

void musicVolume(int percentage) {
	SuperMaximo::musicVolume(percentage);
}

void pauseMusic() {
	SuperMaximo::pauseMusic();
}

void resumeMusic() {
	SuperMaximo::resumeMusic();
}

void restartMusic() {
	SuperMaximo::restartMusic();
}

void stopMusic() {
	SuperMaximo::stopMusic();
}

void fadeMusic(int time) {
	SuperMaximo::fadeMusic(time);
}

}
