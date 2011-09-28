/*
 * Font-C.cpp
 *
 *  Created on: 26 Aug 2011
 *      Author: Max Foster
 */

#include <SuperMaximo_GameLibrary/classes/Font.h>

#include "../headers/Font-C.h"

extern "C" {

Font * fontNew(const char * name, const char * fileName, unsigned newSize) {
	return (Font*)(new SuperMaximo::Font(name, fileName, newSize));
}

void fontDelete(Font * font) {
	delete (SuperMaximo::Font*)font;
	font = 0;
}

const char * fontName(Font * font) {
	return ((SuperMaximo::Font*)font)->name().c_str();
}

void fontWrite(Font * font, const char * text, int x, int y, float depth, int useCache, float rotation,
		float xScale, float yScale) {
	((SuperMaximo::Font*)font)->write(text, x, y, depth, useCache, rotation, xScale, yScale);
}

int fontWidth(Font * font, const char * text) {
	return ((SuperMaximo::Font*)font)->width(text);
}

int fontHeight(Font * font, const char * text) {
	return ((SuperMaximo::Font*)font)->height(text);
}

void fontCacheText(Font * font, const char * text) {
	return ((SuperMaximo::Font*)font)->cache(text);
}

void fontRemoveTextFromCache(Font * font, const char * text) {
	return ((SuperMaximo::Font*)font)->removeFromCache(text);
}

void initFont(Shader * newFontShader) {
	SuperMaximo::initFont((SuperMaximo::Shader*)newFontShader);
}

void quitFont() {
	SuperMaximo::quitFont();
}

void bindFontShader(Shader * newFontShader) {
	SuperMaximo::bindFontShader((SuperMaximo::Shader*)newFontShader);
}

}
