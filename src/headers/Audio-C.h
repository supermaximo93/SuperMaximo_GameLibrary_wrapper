/*
 * Audio-C.h
 *
 *  Created on: 26 Aug 2011
 *      Author: maximo
 */

#ifndef AUDIOC_H_
#define AUDIOC_H_

#ifdef __cplusplus
extern "C" {
#endif

void initAudio(unsigned channels);
void quitAudio();

void soundPosition(int channel, int angle, int distance);

void musicVolume(int percentage);

void pauseMusic();
void resumeMusic();
void restartMusic();
void stopMusic();
void fadeMusic(int time);

#ifdef __cplusplus
}
#endif

#endif /* AUDIOC_H_ */
