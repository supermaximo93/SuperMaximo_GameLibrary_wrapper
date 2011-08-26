/*
 * Font-C.h
 *
 *  Created on: 26 Aug 2011
 *      Author: Max Foster
 */

#ifndef FONTC_H_
#define FONTC_H_

#ifdef __cplusplus

class Font;
class Shader;
extern "C" {

#else

typedef struct Font Font;

#endif

Font * fontNew(const char * name, const char * fileName, unsigned newSize);
void fontDelete(Font * font);
const char * fontName(Font * font);
void fontWrite(Font * font, const char * text, int x, int y, float depth, int useCache, float rotation,
		float xScale, float yScale);
int fontWidth(Font * font, const char * text);
int fontHeight(Font * font, const char * text);
void fontCacheText(Font * font, const char * text);
void fontRemoveTextFromCache(Font * font, const char * text);

void initFont(Shader * newFontShader);
void quitFont();
void bindFontShader(Shader * newFontShader);

#ifdef __cplusplus
}
#endif

#endif /* FONTC_H_ */
