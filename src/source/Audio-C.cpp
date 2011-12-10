/*
 * Audio-C.cpp
 *
 *  Created on: 26 Aug 2011
 *      Author: Max Foster
 */

#include <SuperMaximo_GameLibrary/Audio.h>

#include <SuperMaximo_GameLibrary-C/Audio-C.h>

extern "C" {

void initAudio(unsigned channels) {
	SuperMaximo::initAudio(channels);
}

void quitAudio() {
	SuperMaximo::quitAudio();
}

}
