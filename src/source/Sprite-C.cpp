/*
 * Sprite-C.cpp
 *
 *  Created on: 26 Aug 2011
 *      Author: Max Foster
 */

#include "../SuperMaximo_GameLibrary/headers/classes/Sprite.h"
#include "../SuperMaximo_GameLibrary/headers/classes/Shader.h"

#include "../headers/Sprite-C.h"

extern "C" {

Sprite * spriteNew(const char * newName, const char * fileName, int imageX, int imageY, int imageWidth,
		int imageHeight, int aniFrames, unsigned framerate, int newOriginX, int newOriginY) {
	return (Sprite*)(new SuperMaximo::Sprite(newName, fileName, imageX, imageY, imageWidth, imageHeight, aniFrames,
			framerate, newOriginX, newOriginY));
}

void spriteDelete(Sprite * sprite) {
	delete (SuperMaximo::Sprite*)sprite;
}

const char * spriteName(Sprite * sprite) {
	return ((SuperMaximo::Sprite*)sprite)->name().c_str();
}

unsigned spriteFrameCount(Sprite * sprite) {
	return ((SuperMaximo::Sprite*)sprite)->frameCount();
}

void spriteSetFramerate(Sprite * sprite, unsigned newFramerate) {
	((SuperMaximo::Sprite*)sprite)->setFramerate(newFramerate);
}

unsigned spriteFramerate(Sprite * sprite) {
	return ((SuperMaximo::Sprite*)sprite)->framerate();
}

void spriteDraw(Sprite * sprite, int x, int y, float depth, float rotation, float xScale, float yScale, float alpha,
		unsigned frame, Shader * shaderOverride) {
	((SuperMaximo::Sprite*)sprite)->draw(x, y, depth, rotation, xScale,yScale, alpha, frame,
			(SuperMaximo::Shader*)shaderOverride);
}

void spriteDrawObject(Sprite * sprite, Object * object) {
	((SuperMaximo::Sprite*)sprite)->draw((SuperMaximo::Object*)object);
}

int spriteWidth(Sprite * sprite) {
	return ((SuperMaximo::Sprite*)sprite)->width();
}

int spriteHeight(Sprite * sprite) {
	return ((SuperMaximo::Sprite*)sprite)->height();
}

unsigned spriteTexture(Sprite * sprite, unsigned frame) {
	return ((SuperMaximo::Sprite*)sprite)->texture(frame);
}

void spriteBindShader(Sprite * sprite, Shader * shader) {
	((SuperMaximo::Sprite*)sprite)->bindShader((SuperMaximo::Shader*)shader);
}

Shader * spriteBoundShader(Sprite * sprite) {
	return (Shader*)((SuperMaximo::Sprite*)sprite)->boundShader();
}

}
