/*
 * SMSDL-C.h
 *
 *  Created on: 25 Aug 2011
 *      Author: Max Foster
 */

#ifndef SMSDL_C_H_
#define SMSDL_C_H_

#ifdef __cplusplus
extern "C" {
#else
#include <stdint.h>
#endif

#define SDL_INIT_TIMER	0x00000001
#define SDL_INIT_AUDIO	0x00000010
#define SDL_INIT_VIDEO	0x00000020
#define SDL_INIT_CDROM	0x00000100
#define SDL_INIT_JOYSTICK 0x00000200
#define SDL_INIT_NOPARACHUTE 0x00100000
#define SDL_INIT_EVENTTHREAD 0x01000000
#define SDL_INIT_EVERYTHING 0x0000FFFF

void initSDL(uint32_t flags);
void quitSDL();

void wait(long time);

#ifdef __cplusplus
}
#endif

#endif /* SMSDL_C_H_ */
