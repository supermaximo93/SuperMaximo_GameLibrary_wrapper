/*
 * SMSDL.cpp
 *
 *  Created on: 25 Aug 2011
 *      Author: Max Foster
 */

#include "../SuperMaximo_GameLibrary/headers/SMSDL.h"

#include "../headers/SMSDL.h"

extern "C" {

void initSDL(Uint32 flags) {
	SuperMaximo::initSDL(flags);
}

void quitSDL() {
	SuperMaximo::quitSDL();
}

void wait(long time) {
	SuperMaximo::wait(time);
}

}
