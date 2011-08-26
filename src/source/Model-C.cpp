/*
 * Model-C.cpp
 *
 *  Created on: 26 Aug 2011
 *      Author: Max Foster
 */

#include "../SuperMaximo_GameLibrary/headers/classes/Model.h"

#include "../headers/Model-C.h"

extern "C" {

Model * modelNew(const char * newName, const char * path, const char * fileName, unsigned framerate,
		bufferUsageEnum bufferUsage) {
	return (Model*)(new SuperMaximo::Model(newName, path, fileName, framerate,
			(SuperMaximo::bufferUsageEnum)bufferUsage, 0, 0));
}

void modelDelete(Model * model) {
	delete (SuperMaximo::Model*)model;
	model = 0;
}

const char * modelName(Model * model) {
	return ((SuperMaximo::Model*)model)->name().c_str();
}

void modelDrawObject(Model * model, Object * object, int skipAnimation) {
	((SuperMaximo::Model*)model)->draw((SuperMaximo::Object*)object, skipAnimation);
}

void modelDraw(Model * model, float x, float y, float z, float xRotation, float yRotation, float zRotation,
		float xScale, float yScale, float zScale, float frame, int currentAnimationId, int skipAnimation) {
	((SuperMaximo::Model*)model)->draw(x, y, z, xRotation, yRotation, zRotation, xScale, yScale, zScale, frame,
			currentAnimationId, skipAnimation);
}

void modelBindShader(Model * model, Shader * shader) {
	((SuperMaximo::Model*)model)->bindShader((SuperMaximo::Shader*)shader);
}

Shader * modelBoundShader(Model * model) {
	return (Shader*)((SuperMaximo::Model*)model)->boundShader();
}

int modelBoneId(Model * model, const char * boneName) {
	return ((SuperMaximo::Model*)model)->boneId(boneName);
}

const char * modelBoneName(Model * model, unsigned boneId) {
	return ((SuperMaximo::Model*)model)->boneName(boneId).c_str();
}

int modelAnimationId(Model * model, const char * searchName) {
	return ((SuperMaximo::Model*)model)->animationId(searchName);
}

void modelSetFramerate(Model * model, unsigned newFramerate) {
	((SuperMaximo::Model*)model)->setFramerate(newFramerate);
}

unsigned modelFramerate(Model * model) {
	return ((SuperMaximo::Model*)model)->framerate();
}

unsigned * modelVboPointer(Model * model) {
	return ((SuperMaximo::Model*)model)->vboPointer();
}

unsigned modelVertexCount(Model * model) {
	return ((SuperMaximo::Model*)model)->vertexCount();
}

}
