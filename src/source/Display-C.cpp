/*
 * Display-C.cpp
 *
 *  Created on: 25 Aug 2011
 *      Author: Max Foster
 */
#include <iostream>
using namespace std;
#include "../SuperMaximo_GameLibrary/headers/Display.h"

#include "../headers/Display-C.h"

extern "C" {

mat2 * mat2New() {
	return (mat2*)(new SuperMaximo::mat2);
}

void mat2Copy(mat2 * srcMatrix, mat2 * dstMatrix) {
	*((SuperMaximo::mat2*)dstMatrix) = *((SuperMaximo::mat2*)srcMatrix);
}

float mat2Component(mat2 * matrix, int index) {
	return ((SuperMaximo::mat2*)matrix)->component[index];
}

void mat2AssignComponent(mat2 * matrix, int index, float value) {
	 ((SuperMaximo::mat2*)matrix)->component[index] = value;
}

void mat2MultiplyMat2(mat2 * matrix, mat2 * otherMatrix) {
	*((SuperMaximo::mat2*)matrix) = (*((SuperMaximo::mat2*)matrix))*(*((SuperMaximo::mat2*)otherMatrix));
}

void mat2InitIdentity(mat2 * matrix, mat2 * otherMatrix) {
	((SuperMaximo::mat2*)matrix)->initIdentity();
}

mat3 * mat3New() {
	return (mat3*)(new SuperMaximo::mat3);
}

void mat3Copy(mat3 * srcMatrix, mat3 * dstMatrix) {
	*((SuperMaximo::mat3*)dstMatrix) = *((SuperMaximo::mat3*)srcMatrix);
}

float mat3Component(mat3 * matrix, int index) {
	return ((SuperMaximo::mat3*)matrix)->component[index];
}

void mat3AssignComponent(mat3 * matrix, int index, float value) {
	 ((SuperMaximo::mat3*)matrix)->component[index] = value;
}

void mat3MultiplyMat3(mat3 * matrix, mat3 * otherMatrix) {
	*((SuperMaximo::mat3*)matrix) = (*((SuperMaximo::mat3*)matrix))*(*((SuperMaximo::mat3*)otherMatrix));
}

void mat3InitIdentity(mat3 * matrix, mat3 * otherMatrix) {
	((SuperMaximo::mat3*)matrix)->initIdentity();
}

mat4 * mat4New() {
	return (mat4*)(new SuperMaximo::mat4);
}

void mat4Copy(mat4 * srcMatrix, mat4 * dstMatrix) {
	*((SuperMaximo::mat4*)dstMatrix) = *((SuperMaximo::mat4*)srcMatrix);
}

float mat4Component(mat4 * matrix, int index) {
	return ((SuperMaximo::mat4*)matrix)->component[index];
}

void mat4AssignComponent(mat4 * matrix, int index, float value) {
	 ((SuperMaximo::mat4*)matrix)->component[index] = value;
}

void mat4MultiplyMat4(mat4 * matrix, mat4 * otherMatrix) {
	*((SuperMaximo::mat4*)matrix) = (*((SuperMaximo::mat4*)matrix))*(*((SuperMaximo::mat4*)otherMatrix));
}

void mat4InitIdentity(mat4 * matrix, mat4 * otherMatrix) {
	((SuperMaximo::mat4*)matrix)->initIdentity();
}


vec2 * vec2New() {
	return (vec2*)(new SuperMaximo::vec2);
}

void vec2Copy(vec2 * srcVec, vec2 * dstVec) {
	*((SuperMaximo::vec2*)dstVec) = *((SuperMaximo::vec2*)srcVec);
}

float vec2Component(vec2 * vec, char component) {
	switch (component) {
	case 'x':
	case 'r':
	case 's': return ((SuperMaximo::vec2*)vec)->x;
	case 'y':
	case 'g':
	case 't': return ((SuperMaximo::vec2*)vec)->y;
	default: return 0;
	}
}

void vec2AssignComponent(vec2 * vec, char component, float value) {
	switch (component) {
	case 'x':
	case 'r':
	case 's': ((SuperMaximo::vec2*)vec)->x = value; break;
	case 'y':
	case 'g':
	case 't': ((SuperMaximo::vec2*)vec)->y = value; break;
	default: break;
	}
}

void vec2MultiplyMat2(vec2 * vec, mat2 * matrix) {
	*((SuperMaximo::vec2*)vec) *= (*((SuperMaximo::mat2*)matrix));
}

void vec2MultiplyFloat(vec2 * vec, float value) {
	*((SuperMaximo::vec2*)vec) *= value;
}

void vec2DivideFloat(vec2 * vec, float value) {
	*((SuperMaximo::vec2*)vec) /= value;
}

vec2 * vec2Perpendicular(vec2 * vec) {
	SuperMaximo::vec2 * returnVec = new SuperMaximo::vec2;
	*returnVec = ((SuperMaximo::vec2*)vec)->perpendicular();
	return (vec2*)returnVec;
}

float vec2DotProduct(vec2 * vec, vec2 * otherVec) {
	return ((SuperMaximo::vec2*)vec)->dotProduct(*((SuperMaximo::vec2*)otherVec));
}

int vec2PolygonCollision(vec2 * vec, unsigned vertexCount, vec2 ** vertices) {
	SuperMaximo::vec2 vec2Arr[vertexCount];
	for (unsigned i = 0; i < vertexCount; i++) vec2Arr[i] = *((SuperMaximo::vec2*)vertices[i]);
	return ((SuperMaximo::vec2*)vec)->polygonCollision(vertexCount, vec2Arr);
}


int initDisplay(unsigned width, unsigned height, unsigned depth, unsigned maxFramerate, int fullScreen,
		const char * windowTitle) {
	return SuperMaximo::initDisplay(width, height, depth, maxFramerate, fullScreen, windowTitle);
}

void quitDisplay() {
	SuperMaximo::quitDisplay();
}

unsigned screenWidth() {
	return SuperMaximo::screenWidth();
}

unsigned screenHeight() {
	return SuperMaximo::screenHeight();
}

unsigned screenDepth() {
	return SuperMaximo::screenDepth();
}

int resizeScreen(unsigned width, unsigned height, int fullScreen) {
	return SuperMaximo::resizeScreen(width, height, fullScreen);
}

void setClearColor(float r, float g, float b, float a) {
	SuperMaximo::setClearColor(r, g, b, a);
}

void getClearColor(float * r, float * g, float * b, float * a) {
	SuperMaximo::vec4 clearColor = SuperMaximo::getClearColor();
	*r = clearColor.r;
	*g = clearColor.g;
	*b = clearColor.b;
	*a = clearColor.a;
}

mat4 * getPerspectiveMatrix6(float left, float right, float bottom, float top, float near, float far) {
	SuperMaximo::mat4 * returnMatrix = new SuperMaximo::mat4;
	*returnMatrix = SuperMaximo::getPerspectiveMatrix(left, right, bottom, top, near, far);
	return (mat4*)returnMatrix;
}

mat4 * getPerspectiveMatrix4(float angle, float aspectRatio, float front, float back) {
	SuperMaximo::mat4 * returnMatrix = new SuperMaximo::mat4;
	*returnMatrix = SuperMaximo::getPerspectiveMatrix(angle, aspectRatio, front, back);
	return (mat4*)returnMatrix;
}

mat4 * getOrthographicMatrix(float left, float right, float bottom, float top, float near, float far) {
	SuperMaximo::mat4 * returnMatrix = new SuperMaximo::mat4;
	*returnMatrix = SuperMaximo::getOrthographicMatrix(left, right, bottom, top, near, far);
	return (mat4*)returnMatrix;
}

mat2 * get2dRotationMatrix(float angle) {
	SuperMaximo::mat2 * returnMatrix = new SuperMaximo::mat2;
	*returnMatrix = SuperMaximo::get2dRotationMatrix(angle);
	return (mat2*)returnMatrix;
}

void bindShader(Shader * shader) {
	SuperMaximo::bindShader((SuperMaximo::Shader*)shader);
}

Shader * boundShader() {
	return (Shader*)SuperMaximo::boundShader();
}

void bindTextureUnit(textureUnitEnum textureUnit) {
	SuperMaximo::bindTextureUnit((SuperMaximo::textureUnitEnum)textureUnit);
}

textureUnitEnum boundTexureUnit() {
	return (textureUnitEnum)SuperMaximo::boundTexureUnit();
}

void setMatrix(matrixEnum matrixId) {
	SuperMaximo::setMatrix((SuperMaximo::matrixEnum)matrixId);
}

matrixEnum currentMatrix() {
	return (matrixEnum)SuperMaximo::currentMatrix();
}

void copyMatrix(matrixEnum srcMatrixId, matrixEnum dstMatrixId) {
	copyMatrix((SuperMaximo::matrixEnum)srcMatrixId, (SuperMaximo::matrixEnum)dstMatrixId);
}

void copyMat4ToMatrix(mat4 * srcMatrix, matrixEnum dstMatrixId) {
	copyMatrix(*((SuperMaximo::mat4*)srcMatrix), (SuperMaximo::matrixEnum)dstMatrixId);
}

mat4 * getMatrix(matrixEnum matrixId) {
	SuperMaximo::mat4 * returnMatrix = new SuperMaximo::mat4;
	*returnMatrix = SuperMaximo::getMatrix((SuperMaximo::matrixEnum)matrixId);
	return (mat4*)returnMatrix;
}

void pushMatrix() {
	SuperMaximo::pushMatrix();
}

void popMatrix() {
	SuperMaximo::popMatrix();
}

void translateMatrix(float x, float y, float z) {
	SuperMaximo::translateMatrix(x, y, z);
}

void rotateMatrix(float angle, float x, float y, float z) {
	SuperMaximo::rotateMatrix(angle, x, y, z);
}

void scaleMatrix(float xScale, float yScale, float zScale) {
	SuperMaximo::scaleMatrix(xScale, yScale, zScale);
}

void refreshScreen() {
	SuperMaximo::refreshScreen();
}

unsigned getFramerate() {
	return SuperMaximo::getFramerate();
}

unsigned getTickDifference() {
	return SuperMaximo::getTickDifference();
}

void setIdealFramerate(unsigned newIdealFramerate) {
	SuperMaximo::setIdealFramerate(newIdealFramerate);
}

unsigned getIdealFramerate() {
	return SuperMaximo::getIdealFramerate();
}

float compensation() {
	return SuperMaximo::compensation();
}

void enableBlending(blendFuncEnum srcBlendFunc, blendFuncEnum dstBlendFunc, blendFuncEquEnum blendFuncEquation) {
	SuperMaximo::enableBlending((SuperMaximo::blendFuncEnum)srcBlendFunc, (SuperMaximo::blendFuncEnum)dstBlendFunc,
			(SuperMaximo::blendFuncEquEnum)blendFuncEquation);
}

void disableBlending() {
	SuperMaximo::disableBlending();
}

int blendingEnabled() {
	return SuperMaximo::blendingEnabled();
}

void enableDepthTesting() {
	SuperMaximo::enableDepthTesting();
}

void disableDepthTesting() {
	SuperMaximo::disableDepthTesting();
}

int depthTestingEnabled() {
	return SuperMaximo::depthTestingEnabled();
}

float openGlVersion() {
	return SuperMaximo::openGlVersion();
}

float glSlVersion() {
	return SuperMaximo::glSlVersion();
}

int vertexArrayObjectSupported() {
	return SuperMaximo::vertexArrayObjectSupported();
}

void disableTexture2dArray() {
	SuperMaximo::disableTexture2dArray();
}

int texture2dArrayDisabled() {
	return SuperMaximo::texture2dArrayDisabled();
}

}
