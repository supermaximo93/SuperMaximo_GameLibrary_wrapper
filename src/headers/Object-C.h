/*
 * Object-C.h
 *
 *  Created on: 26 Aug 2011
 *      Author: Max Foster
 */

#ifndef OBJECTC_H_
#define OBJECTC_H_

#include "Display-C.h"

#ifdef __cplusplus
extern "C" {
#endif

Object * objectNewSprite(const char * newName, float destX, float destY, float destZ, Sprite * newSprite);
Object * objectNewModel(const char * newName, float destX, float destY, float destZ, Model * newModel);
void objectDelete(Object * object);

const char * objectName(Object * object);
void objectSetSprite(Object * object, Sprite * newSprite);
Sprite * objectSprite(Object * object);
void objectSetModel(Object * object, Model * newModel);
Model * objectModel(Object * object);
int objectHasModel(Object * object);

void objectBindShader(Object * object, Shader * shader);
Shader * objectBoundShader(Object * object);

void objectSetPosition(Object * object, float xAmount, float yAmount, float zAmount, int relative);
void objectSetPositionVec2(Object * object, vec2 * amount, int relative);
void objectSetPositionVec3(Object * object, vec3 * amount, int relative);
float objectSetX(Object * object, float amount, int relative);
float objectSetY(Object * object, float amount, int relative);
float objectSetZ(Object * object, float amount, int relative);
float objectX(Object * object);
float objectY(Object * object);
float objectZ(Object * object);

float objectWidth(Object * object);
float objectHeight(Object * object);

void objectScale(Object * object, float xAmount, float yAmount, float zAmount, int relative);
float objectSetXScale(Object * object, float amount, int relative);
float objectSetYScale(Object * object, float amount, int relative);
float objectSetZScale(Object * object, float amount, int relative);
float objectXScale(Object * object);
float objectYScale(Object * object);
float objectZScale(Object * object);

void objectRotate(Object * object, float xAmount, float yAmount, float zAmount, int relative);
float objectSetXRotation(Object * object, float amount, int relative);
float objectSetYRotation(Object * object, float amount, int relative);
float objectSetZRotation(Object * object, float amount, int relative);
float objectXRotation(Object * object);
float objectYRotation(Object * object);
float objectZRotation(Object * object);

float objectSetAlpha(Object * object, float amount, int relative);
float objectAlpha(Object * object);

void objectSetCurrentAnimation(Object * object, unsigned animationId, int boneId, int withChildren);
unsigned objectCurrentAnimation(Object * object, int boneId);

void objectSetFrame(Object * object, float newFrame, int relative, int boneId, int withChildren);
float objectFrame(Object * object, int boneId);

void objectDraw(Object * object, int skipAnimation);

int objectRoughMouseOverBox(Object * object);
int objectMouseOverBox(Object * object);
int objectMouseOverCircle(Object * object);
int objectBoxCollision(Object * object, Object * otherObject, int allStages);
int objectRoughBoxCollision(Object * object, Object * otherObject);
int objectCircleCollision(Object * object, Object * otherObject);

#ifdef __cplusplus
}
#endif


#endif /* OBJECTC_H_ */
