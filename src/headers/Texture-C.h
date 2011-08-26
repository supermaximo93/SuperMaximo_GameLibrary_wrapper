/*
 * Texture-C.h
 *
 *  Created on: 26 Aug 2011
 *      Author: Max Foster
 */

#ifndef TEXTUREC_H_
#define TEXTUREC_H_

#include "Display-C.h"

#ifdef __cplusplus
extern "C" {
#endif

enum textureTypeEnum {
	TEXTURE_1D = 0x0DE0,
	TEXTURE_2D = 0x0DE1,
	TEXTURE_3D = 0x806F,
	TEXTURE_RECTANGLE = 0x84F5,
	TEXTURE_CUBE = 0x8513
};

Texture * textureNew(const char * newName, enum textureTypeEnum textureType, unsigned numLayers,
		const char ** fileNames);
void textureDelete(Texture * texture);
void textureReload(Texture * texture, enum textureTypeEnum textureType, unsigned numLayers, const char ** fileNames);

const char * textureName(Texture * texture);
enum textureTypeEnum textureType(Texture * texture);
unsigned textureData(Texture * texture);

#ifdef __cplusplus
}
#endif

#endif /* TEXTUREC_H_ */
