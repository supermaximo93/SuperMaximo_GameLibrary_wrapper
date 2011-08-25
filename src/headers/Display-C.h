/*
 * Display-C.h
 *
 *  Created on: 25 Aug 2011
 *      Author: Max Foster
 */

#ifndef DISPLAY_C_H_
#define DISPLAY_C_H_

#ifdef __cplusplus

class Shader;

struct mat2;
struct mat3;
struct mat4;

struct vec2;
struct vec3;
struct vec4;

extern "C" {
#else

typedef struct Shader Shader;

typedef struct mat2 mat2;
typedef struct mat3 mat3;
typedef struct mat4 mat4;

typedef struct vec2 vec2;
typedef struct vec3 vec3;
typedef struct vec4 vec4;

#endif

enum textureUnitEnum {
	TEXTURE0 = 0x84C0,
	TEXTURE1 = 0x84C1,
	TEXTURE2 = 0x84C2,
	TEXTURE3 = 0x84C3,
	TEXTURE4 = 0x84C4,
	TEXTURE5 = 0x84C5,
	TEXTURE6 = 0x84C6,
	TEXTURE7 = 0x84C7,
	TEXTURE8 = 0x84C8,
	TEXTURE9 = 0x84C9,
	TEXTURE10 = 0x84CA,
	TEXTURE11 = 0x84CB,
	TEXTURE12 = 0x84CC,
	TEXTURE13 = 0x84CD,
	TEXTURE14 = 0x84CE,
	TEXTURE15 = 0x84CF
};

enum matrixEnum {
	MODELVIEW_MATRIX = 0,
	PERSPECTIVE_MATRIX,
	ORTHOGRAPHIC_MATRIX,
	PROJECTION_MATRIX,
	IDENTITY_MATRIX
};

enum blendFuncEnum {
	ZERO = 0,
	ONE = 1,
	SRC_COLOR = 0x0300,
	ONE_MINUS_SRC_COLOR = 0x0301,
	DST_COLOR = 0x0306,
	ONE_MINUS_DST_COLOR = 0x0307,
	SRC_ALPHA = 0x0302,
	ONE_MINUS_SRC_ALPHA = 0x0303,
	DST_ALPHA = 0x0304,
	ONE_MINUS_DST_ALPHA = 0x0305,
	CONSTANT_COLOR = 0x8001,
	ONE_MINUS_CONSTANT_COLOR = 0x8002,
	CONSTANT_ALPHA = 0x8003,
	ONE_MINUS_CONSTANT_ALPHA = 0x8004,
	SRC_ALPHA_SATURATE = 0x0308
};

enum blendFuncEquEnum {
	FUNC_ADD = 0x8006,
	FUNC_SUBTRACT = 0x800A,
	FUNC_REVERSE_SUBTRACT = 0x800B,
	MIN = 0x8007,
	MAX = 0x8008
};

int initDisplay(unsigned width, unsigned height, unsigned depth, unsigned maxFramerate, int fullScreen,
		const char * windowTitle);
void quitDisplay();

unsigned screenWidth();
unsigned screenHeight();
unsigned screenDepth();
int resizeScreen(unsigned width, unsigned height, int fullScreen);

void setClearColor(float r, float g, float b, float a);
void getClearColor(float * r, float * g, float * b, float * a);

mat4 * getPerspectiveMatrix6(float left, float right, float bottom, float top, float near, float far);
mat4 * getPerspectiveMatrix4(float angle, float aspectRatio, float front, float back);
mat4 * getOrthographicMatrix(float left, float right, float bottom, float top, float near, float far);

mat2 * get2dRotationMatrix(float angle);

void bindShader(Shader * shader);
Shader * boundShader();

void bindTextureUnit(textureUnitEnum textureUnit);
textureUnitEnum boundTexureUnit();

void setMatrix(matrixEnum matrixId);
matrixEnum currentMatrix();
void copyMatrix(matrixEnum srcMatrixId, matrixEnum dstMatrixId);
void copyMat4ToMatrix(mat4 * srcMatrix, matrixEnum dstMatrixId);
mat4 * getMatrix(matrixEnum matrixId);
void pushMatrix();
void popMatrix();

void translateMatrix(float x, float y, float z);
void rotateMatrix(float angle, float x, float y, float z);
void scaleMatrix(float xScale, float yScale, float zScale);

void refreshScreen();
unsigned getFramerate();
unsigned getTickDifference();
void setIdealFramerate(unsigned newIdealFramerate);
unsigned getIdealFramerate();
float compensation();

void enableBlending(blendFuncEnum srcBlendFunc, blendFuncEnum dstBlendFunc, blendFuncEquEnum blendFuncEquation);
void disableBlending();
int blendingEnabled();

void enableDepthTesting();
void disableDepthTesting();
int depthTestingEnabled();

float openGlVersion();
float glSlVersion();

int vertexArrayObjectSupported();

void disableTexture2dArray();
int texture2dArrayDisabled();

#ifdef __cplusplus
}
#endif

#endif /* DISPLAY_C_H_ */
