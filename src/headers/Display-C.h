/*
 * Display-C.h
 *
 *  Created on: 25 Aug 2011
 *      Author: Max Foster
 */

#ifndef DISPLAYC_H_
#define DISPLAYC_H_

#ifdef __cplusplus

class Shader;
class Sprite;
class Model;
class Object;
class Texture;

struct mat2;
struct mat3;
struct mat4;

struct vec2;
struct vec3;
struct vec4;

extern "C" {
#else

typedef struct Shader Shader;
typedef struct Sprite Sprite;
typedef struct Model Model;
typedef struct Object Object;
typedef struct Texture Texture;

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


mat2 * mat2New();
void mat2Delete(mat2 * matrix);
void mat2Copy(mat2 * srcMatrix, mat2 * dstMatrix);
float * mat2Arr(mat2 * matrix);
float mat2Component(mat2 * matrix, int index);
void mat2AssignComponent(mat2 * matrix, int index, float value);
void mat2MultiplyMat2(mat2 * matrix, mat2 * otherMatrix);
void mat2InitIdentity(mat2 * matrix);

mat3 * mat3New();
void mat3Delete(mat3 * matrix);
void mat3Copy(mat3 * srcMatrix, mat3 * dstMatrix);
float * mat3Arr(mat3 * matrix);
float mat3Component(mat3 * matrix, int index);
void mat3AssignComponent(mat3 * matrix, int index, float value);
void mat3MultiplyMat3(mat3 * matrix, mat3 * otherMatrix);
void mat3InitIdentity(mat3 * matrix);

mat4 * mat4New();
void mat4Delete(mat4 * matrix);
void mat4Copy(mat4 * srcMatrix, mat4 * dstMatrix);
float * mat4Arr(mat4 * matrix);
float mat4Component(mat4 * matrix, int index);
void mat4AssignComponent(mat4 * matrix, int index, float value);
void mat4MultiplyMat4(mat4 * matrix, mat4 * otherMatrix);
void mat4InitIdentity(mat4 * matrix);

vec2 * vec2New();
void vec2Delete(vec2 * vec);
void vec2Copy(vec2 * srcVec, vec2 * dstVec);
float vec2Component(vec2 * vec, char component);
void vec2AssignComponent(vec2 * vec, char component, float value);
void vec2AddVec2(vec2 * vec, vec2 * otherVec);
void vec2SubtractVec2(vec2 * vec , vec2 * otherVec);
void vec2MultiplyMat2(vec2 * vec, mat2 * matrix);
void vec2MultiplyFloat(vec2 * vec, float value);
void vec2DivideFloat(vec2 * vec, float value);
vec2 * vec2Perpendicular(vec2 * vec);
float vec2DotProduct(vec2 * vec, vec2 * otherVec);
int vec2PolygonCollision(vec2 * vec, unsigned vertexCount, vec2 ** vertices);

vec3 * vec3New();
void vec3Delete(vec3 * vec);
void vec3Copy(vec3 * srcVec, vec3 * dstVec);
float vec3Component(vec3 * vec, char component);
void vec3AssignComponent(vec3 * vec, char component, float value);
void vec3AddVec3(vec3 * vec, vec3 * otherVec);
void vec3SubtractVec3(vec3 * vec , vec3 * otherVec);
void vec3MultiplyFloat(vec3 * vec, float value);
void vec3DivideFloat(vec3 * vec, float value);
float vec3DotProduct(vec3 * vec, vec3 * otherVec);

vec4 * vec4New();
void vec4Delete(vec4 * vec);
void vec4Copy(vec4 * srcVec, vec4 * dstVec);
float vec4Component(vec4 * vec, char component);
void vec4AssignComponent(vec4 * vec, char component, float value);
void vec4AddVec4(vec4 * vec, vec4 * otherVec);
void vec4SubtractVec4(vec4 * vec , vec4 * otherVec);
void vec4MultiplyFloat(vec4 * vec, float value);
void vec4DivideFloat(vec4 * vec, float value);
float vec4DotProduct(vec4 * vec, vec4 * otherVec);


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

void bindTextureUnit(enum textureUnitEnum textureUnit);
enum textureUnitEnum boundTexureUnit();

void setMatrix(enum matrixEnum matrixId);
enum matrixEnum currentMatrix();
void copyMatrix(enum matrixEnum srcMatrixId, enum matrixEnum dstMatrixId);
void copyMat4ToMatrix(mat4 * srcMatrix, enum matrixEnum dstMatrixId);
mat4 * getMatrix(enum matrixEnum matrixId);
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

void enableBlending(enum blendFuncEnum srcBlendFunc, enum blendFuncEnum dstBlendFunc,
		enum blendFuncEquEnum blendFuncEquation);
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

#endif /* DISPLAYC_H_ */
