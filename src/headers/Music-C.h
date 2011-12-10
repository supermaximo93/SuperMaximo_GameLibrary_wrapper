/*
 * Music-c.h
 *
 *  Created on: 26 Aug 2011
 *      Author: Max Foster
 */

#ifndef MUSICC_H_
#define MUSICC_H_

#ifdef __cplusplus

class Music;
extern "C" {

#else

typedef struct Music Music;

#endif

Music * musicNew(const char * newName, const char * fileName);
void musicDelete(Music * music);

const char * musicName(Music * music);
void musicPlay(Music * music);

int musicVolume();
int musicSetVolume(int percentage, bool relative);

void musicPause();
void musicResume();
void musicRestart();
void musicStop();
void musicFadeOut(unsigned time);

#ifdef __cplusplus
}
#endif

#endif /* MUSICC_H_ */
