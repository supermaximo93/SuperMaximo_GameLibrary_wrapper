/*
 * Sprite-C.h
 *
 *  Created on: 26 Aug 2011
 *      Author: Max Foster
 */

#ifndef SPRITEC_H_
#define SPRITEC_H_

#include "Display-C.h"

#ifdef __cplusplus

class Sprite;
extern "C" {
#endif

Sprite * spriteNew(const char * newName, const char * fileName, int imageX, int imageY, int imageWidth,
		int imageHeight, int aniFrames, unsigned framerate, int newOriginX, int newOriginY);
void spriteDelete(Sprite * sprite);

const char * spriteName(Sprite * sprite);

unsigned spriteFrameCount(Sprite * sprite);
void spriteSetFramerate(Sprite * sprite, unsigned newFramerate);
unsigned spriteFramerate(Sprite * sprite);

void spriteDraw(Sprite * sprite, int x, int y, float depth, float rotation, float xScale, float yScale, float alpha,
		unsigned frame, Shader * shaderOverride);

void spriteDrawObject(Sprite * sprite, Object * object);

int spriteWidth(Sprite * sprite);
int spriteHeight(Sprite * sprite);

unsigned spriteTexture(Sprite * sprite, unsigned frame);

void spriteBindShader(Sprite * sprite, Shader * shader);
Shader * spriteBoundShader(Sprite * sprite);

#ifdef __cplusplus
}
#endif

#endif /* SPRITEC_H_ */
