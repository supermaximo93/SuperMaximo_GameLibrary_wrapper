/*
 * Texture-C.cpp
 *
 *  Created on: 26 Aug 2011
 *      Author: Max Foster
 */

#include <iostream>
using namespace std;

#include <SuperMaximo_GameLibrary/classes/Texture.h>

#include "../headers/Texture-C.h"

extern "C" {

Texture * textureNew(const char * newName, textureTypeEnum textureType, unsigned numLayers,
		const char ** fileNames) {
	return (Texture*)(new SuperMaximo::Texture(newName, (SuperMaximo::textureTypeEnum)textureType, numLayers,
			fileNames));
}

void textureDelete(Texture * texture) {
	delete (SuperMaximo::Texture*)texture;
}

void textureReload(Texture * texture, textureTypeEnum textureType, unsigned numLayers, const char ** fileNames) {
	((SuperMaximo::Texture*)texture)->reload((SuperMaximo::textureTypeEnum)textureType, numLayers, (string*)fileNames);
}

const char * textureName(Texture * texture) {
	return ((SuperMaximo::Texture*)texture)->name().c_str();
}

textureTypeEnum textureType(Texture * texture) {
	return (textureTypeEnum)((SuperMaximo::Texture*)texture)->type();
}

unsigned textureData(Texture * texture) {
	return (unsigned)(*((SuperMaximo::Texture*)texture));
}

}
