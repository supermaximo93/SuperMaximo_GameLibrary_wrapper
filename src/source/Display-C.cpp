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
