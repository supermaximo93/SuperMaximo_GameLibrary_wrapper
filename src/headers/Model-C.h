/*
 * Model-C.h
 *
 *  Created on: 26 Aug 2011
 *      Author: Max Foster
 */

#ifndef MODELC_H_
#define MODELC_H_

#ifdef __cplusplus

class Object;
class Shader;
class Model;

struct bone;
struct mat4;

extern "C" {

#else

typedef struct Model Model;
typedef struct Object Object;

#endif

enum bufferUsageEnum {
	STREAM_DRAW = 0x88E0,
	STREAM_READ = 0x88E1,
	STREAM_COPY = 0x88E2,
	STATIC_DRAW = 0x88E4,
	STATIC_READ = 0x88E5,
	STATIC_COPY = 0x88E6,
	DYNAMIC_DRAW = 0x88E8,
	DYNAMIC_READ = 0x88E9,
	DYNAMIC_COPY = 0x88EA
};

Model * modelNew(const char * newName, const char * path, const char * fileName, unsigned framerate,
		enum bufferUsageEnum bufferUsage);
void modelDelete(Model * model);

const char * modelName(Model * model);
void modelDrawObject(Model * model, Object * object, int skipAnimation);
void modelDraw(Model * model, float x, float y, float z, float xRotation, float yRotation, float zRotation,
		float xScale, float yScale, float zScale, float frame, int currentAnimationId, int skipAnimation);

void modelBindShader(Model * model, Shader * shader);
Shader * modelBoundShader(Model * model);

int modelBoneId(Model * model, const char * boneName);
const char * modelBoneName(Model * model, unsigned boneId);

int modelAnimationId(Model * model, const char * searchName);
void modelSetFramerate(Model * model, unsigned newFramerate);
unsigned modelFramerate(Model * model);

unsigned * modelVboPointer(Model * model);

unsigned modelVertexCount(Model * model);

#ifdef __cplusplus
}
#endif

#endif /* MODELC_H_ */
