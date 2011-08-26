/*
 * SMSDL-C.cpp
 *
 *  Created on: 25 Aug 2011
 *      Author: Max Foster
 */

#include "../SuperMaximo_GameLibrary/headers/SMSDL.h"

#include "../headers/SMSDL-C.h"

extern "C" {

void initSDL(uint32_t flags) {
	SuperMaximo::initSDL(flags);
}

void quitSDL() {
	SuperMaximo::quitSDL();
}

void wait(long time) {
	SuperMaximo::wait(time);
}

}
