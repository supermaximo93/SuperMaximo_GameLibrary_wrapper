/*
 * Music-C.cpp
 *
 *  Created on: 26 Aug 2011
 *      Author: Max Foster
 */

#include <SuperMaximo_GameLibrary/classes/Music.h>

#include <SuperMaximo_GameLibrary-C/Music-C.h>

extern "C" {

Music * musicNew(const char * newName, const char * fileName) {
	return (Music*)(new SuperMaximo::Music(newName, fileName));
}

void musicDelete(Music * music) {
	delete (SuperMaximo::Music*)music;
	music = 0;
}

const char * musicName(Music * music) {
	return ((SuperMaximo::Music*)music)->name().c_str();
}

void musicPlay(Music * music) {
	((SuperMaximo::Music*)music)->play();
}

int musicVolume() {
	return SuperMaximo::Music::volume();
}

int musicSetVolume(int percentage, int relative) {
	return SuperMaximo::Music::setVolume(percentage, relative);
}

void musicPause() {
	SuperMaximo::Music::pause();
}

void musicResume() {
	SuperMaximo::Music::resume();
}

void musicRestart() {
	SuperMaximo::Music::restart();
}

void musicStop() {
	SuperMaximo::Music::stop();
}

void musicFadeOut(unsigned time) {
	SuperMaximo::Music::fadeOut(time);
}

}
