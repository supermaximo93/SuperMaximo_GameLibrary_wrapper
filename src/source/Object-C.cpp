/*
 * Object-C.cpp
 *
 *  Created on: 26 Aug 2011
 *      Author: Max Foster
 */

#include "../SuperMaximo_GameLibrary/headers/classes/Object.h"

#include "../headers/Display-C.h"
#include "../headers/Object-C.h"

extern "C" {

Object * objectNewSprite(const char * newName, float destX, float destY, float destZ, Sprite * newSprite) {
	return (Object*)(new SuperMaximo::Object(newName, destX, destY, destZ, (SuperMaximo::Sprite*)newSprite));
}

Object * objectNewModel(const char * newName, float destX, float destY, float destZ, Model * newModel) {
	return (Object*)(new SuperMaximo::Object(newName, destX, destY, destZ, (SuperMaximo::Model*)newModel));
}

void objectDelete(Object * object) {
	delete (SuperMaximo::Object*)object;
}

const char * objectName(Object * object) {
	return ((SuperMaximo::Object*)object)->name().c_str();
}

void objectSetSprite(Object * object, Sprite * newSprite) {
	((SuperMaximo::Object*)object)->setSprite((SuperMaximo::Sprite*)newSprite);
}

Sprite * objectSprite(Object * object) {
	return (Sprite*)((SuperMaximo::Object*)object)->sprite();
}

void objectSetModel(Object * object, Model * newModel) {
	((SuperMaximo::Object*)object)->setModel((SuperMaximo::Model*)newModel);
}

Model * objectModel(Object * object) {
	return (Model*)((SuperMaximo::Object*)object)->model();
}

int objectHasModel(Object * object) {
	return ((SuperMaximo::Object*)object)->hasModel();
}

void objectBindShader(Object * object, Shader * shader) {
	((SuperMaximo::Object*)object)->bindShader((SuperMaximo::Shader*)shader);
}

Shader * objectBoundShader(Object * object) {
	return (Shader*)((SuperMaximo::Object*)object)->boundShader();
}

void objectSetPosition(Object * object, float xAmount, float yAmount, float zAmount, int relative) {
	((SuperMaximo::Object*)object)->setPosition(xAmount, yAmount, zAmount, relative);
}

void objectSetPositionVec2(Object * object, vec2 * amount, int relative) {
	((SuperMaximo::Object*)object)->setPosition(*((SuperMaximo::vec2*)amount), relative);
}

void objectSetPositionVec3(Object * object, vec3 * amount, int relative) {
	((SuperMaximo::Object*)object)->setPosition(*((SuperMaximo::vec3*)amount), relative);
}

float objectSetX(Object * object, float amount, int relative) {
	return ((SuperMaximo::Object*)object)->setX(amount, relative);
}

float objectSetY(Object * object, float amount, int relative) {
	return ((SuperMaximo::Object*)object)->setY(amount, relative);
}

float objectSetZ(Object * object, float amount, int relative) {
	return ((SuperMaximo::Object*)object)->setZ(amount, relative);
}

float objectX(Object * object) {
	return ((SuperMaximo::Object*)object)->x();
}

float objectY(Object * object) {
	return ((SuperMaximo::Object*)object)->y();
}

float objectZ(Object * object) {
	return ((SuperMaximo::Object*)object)->z();
}

float objectWidth(Object * object) {
	return ((SuperMaximo::Object*)object)->width();
}

float objectHeight(Object * object) {
	return ((SuperMaximo::Object*)object)->height();
}

void objectScale(Object * object, float xAmount, float yAmount, float zAmount, int relative) {
	((SuperMaximo::Object*)object)->scale(xAmount, yAmount, zAmount, relative);
}

float objectSetXScale(Object * object, float amount, int relative) {
	return ((SuperMaximo::Object*)object)->setXScale(amount, relative);
}

float objectSetYScale(Object * object, float amount, int relative) {
	return ((SuperMaximo::Object*)object)->setYScale(amount, relative);
}

float objectSetZScale(Object * object, float amount, int relative) {
	return ((SuperMaximo::Object*)object)->setZScale(amount, relative);
}

float objectXScale(Object * object) {
	return ((SuperMaximo::Object*)object)->xScale();
}

float objectYScale(Object * object) {
	return ((SuperMaximo::Object*)object)->yScale();
}

float objectZScale(Object * object) {
	return ((SuperMaximo::Object*)object)->zScale();
}

void objectRotate(Object * object, float xAmount, float yAmount, float zAmount, int relative) {
	((SuperMaximo::Object*)object)->rotate(xAmount, yAmount, zAmount, relative);
}

float objectSetXRotation(Object * object, float amount, int relative) {
	return ((SuperMaximo::Object*)object)->setXRotation(amount, relative);
}

float objectSetYRotation(Object * object, float amount, int relative) {
	return ((SuperMaximo::Object*)object)->setYRotation(amount, relative);
}

float objectSetZRotation(Object * object, float amount, int relative) {
	return ((SuperMaximo::Object*)object)->setZRotation(amount, relative);
}

float objectXRotation(Object * object) {
	return ((SuperMaximo::Object*)object)->xRotation();
}

float objectYRotation(Object * object) {
	return ((SuperMaximo::Object*)object)->yRotation();
}

float objectZRotation(Object * object) {
	return ((SuperMaximo::Object*)object)->zRotation();
}

float objectSetAlpha(Object * object, float amount, int relative) {
	return ((SuperMaximo::Object*)object)->setAlpha(amount, relative);
}

float objectAlpha(Object * object) {
	return ((SuperMaximo::Object*)object)->alpha();
}

void objectSetCurrentAnimation(Object * object, unsigned animationId, int boneId, int withChildren) {
	((SuperMaximo::Object*)object)->setCurrentAnimation(animationId, boneId, withChildren);
}

unsigned objectCurrentAnimation(Object * object, int boneId) {
	return ((SuperMaximo::Object*)object)->currentAnimation(boneId);
}

void objectSetFrame(Object * object, float newFrame, int relative, int boneId, int withChildren) {
	((SuperMaximo::Object*)object)->setFrame(newFrame, relative, boneId, withChildren);
}

float objectFrame(Object * object, int boneId) {
	return ((SuperMaximo::Object*)object)->frame(boneId);
}

void objectDraw(Object * object, int skipAnimation) {
	return ((SuperMaximo::Object*)object)->draw(skipAnimation);
}

int objectRoughMouseOverBox(Object * object) {
	return ((SuperMaximo::Object*)object)->roughMouseOverBox();
}

int objectMouseOverBox(Object * object) {
	return ((SuperMaximo::Object*)object)->mouseOverBox();
}

int objectMouseOverCircle(Object * object) {
	return ((SuperMaximo::Object*)object)->mouseOverCircle();
}

int objectBoxCollision(Object * object, Object * otherObject, int allStages) {
	return ((SuperMaximo::Object*)object)->boxCollision((SuperMaximo::Object*)otherObject, allStages);
}

int objectRoughBoxCollision(Object * object, Object * otherObject) {
	return ((SuperMaximo::Object*)object)->roughBoxCollision((SuperMaximo::Object*)otherObject);
}

int objectCircleCollision(Object * object, Object * otherObject) {
	return ((SuperMaximo::Object*)object)->circleCollision((SuperMaximo::Object*)otherObject);
}

}
