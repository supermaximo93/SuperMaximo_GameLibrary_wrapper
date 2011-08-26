/*
 * Shader-C.cpp
 *
 *  Created on: 26 Aug 2011
 *      Author: Max Foster
 */

#include "../SuperMaximo_GameLibrary/headers/classes/Shader.h"

#include "../headers/Shader-C.h"

extern "C" {

Shader * shaderNew(const char * newName, const char * vertexShaderFile, const char * fragmentShaderFile,
		unsigned count, int * enums, const char ** attributeNames) {
	return (Shader*)(new SuperMaximo::Shader(newName, vertexShaderFile, fragmentShaderFile, count, enums,
			attributeNames));
}

void shaderDelete(Shader * shader) {
	delete (SuperMaximo::Shader*)shader;
}


const char * shaderName(Shader * shader) {
	return ((SuperMaximo::Shader*)shader)->name().c_str();
}

void shaderBind(Shader * shader) {
	((SuperMaximo::Shader*)shader)->bind();
}

void shaderUse(Shader * shader) {
	((SuperMaximo::Shader*)shader)->use();
}

unsigned shaderProgram(Shader * shader) {
	return ((SuperMaximo::Shader*)shader)->program();
}

unsigned shaderSetUniformLocation(Shader * shader, shaderLocationEnum dstLocation, const char * locationName) {
	return ((SuperMaximo::Shader*)shader)->setUniformLocation((SuperMaximo::shaderLocationEnum)dstLocation,
			locationName);
}

unsigned shaderUniformLocation(Shader * shader, shaderLocationEnum location) {
	return ((SuperMaximo::Shader*)shader)->uniformLocation((SuperMaximo::shaderLocationEnum)location);
}


void shaderSetUniform1fa(Shader * shader, shaderLocationEnum location, float * data, unsigned count) {
	((SuperMaximo::Shader*)shader)->setUniform1((SuperMaximo::shaderLocationEnum)location, data, count);
}

void shaderSetUniform2fa(Shader * shader, shaderLocationEnum location, float * data, unsigned count) {
	((SuperMaximo::Shader*)shader)->setUniform2((SuperMaximo::shaderLocationEnum)location, data, count);
}

void shaderSetUniform3fa(Shader * shader, shaderLocationEnum location, float * data, unsigned count) {
	((SuperMaximo::Shader*)shader)->setUniform3((SuperMaximo::shaderLocationEnum)location, data, count);
}

void shaderSetUniform4fa(Shader * shader, shaderLocationEnum location, float * data, unsigned count) {
	((SuperMaximo::Shader*)shader)->setUniform4((SuperMaximo::shaderLocationEnum)location, data, count);
}


void shaderSetUniform9fa(Shader * shader, shaderLocationEnum location, float * data, unsigned count) {
	((SuperMaximo::Shader*)shader)->setUniform9((SuperMaximo::shaderLocationEnum)location, data, count);
}

void shaderSetUniform16fa(Shader * shader, shaderLocationEnum location, float * data, unsigned count) {
	((SuperMaximo::Shader*)shader)->setUniform16((SuperMaximo::shaderLocationEnum)location, data, count);
}


void shaderSetUniform1ia(Shader * shader, shaderLocationEnum location, int * data, unsigned count) {
	((SuperMaximo::Shader*)shader)->setUniform1((SuperMaximo::shaderLocationEnum)location, data, count);
}

void shaderSetUniform2ia(Shader * shader, shaderLocationEnum location, int * data, unsigned count) {
	((SuperMaximo::Shader*)shader)->setUniform2((SuperMaximo::shaderLocationEnum)location, data, count);
}

void shaderSetUniform3ia(Shader * shader, shaderLocationEnum location, int * data, unsigned count) {
	((SuperMaximo::Shader*)shader)->setUniform3((SuperMaximo::shaderLocationEnum)location, data, count);
}

void shaderSetUniform4ia(Shader * shader, shaderLocationEnum location, int * data, unsigned count) {
	((SuperMaximo::Shader*)shader)->setUniform4((SuperMaximo::shaderLocationEnum)location, data, count);
}


void shaderSetUniform1f(Shader * shader, shaderLocationEnum location, float data) {
	((SuperMaximo::Shader*)shader)->setUniform1((SuperMaximo::shaderLocationEnum)location, data);
}

void shaderSetUniform2f(Shader * shader, shaderLocationEnum location, float data1, float data2) {
	((SuperMaximo::Shader*)shader)->setUniform2((SuperMaximo::shaderLocationEnum)location, data1, data2);
}

void shaderSetUniform3f(Shader * shader, shaderLocationEnum location, float data1, float data2, float data3) {
	((SuperMaximo::Shader*)shader)->setUniform3((SuperMaximo::shaderLocationEnum)location, data1, data2, data3);
}

void shaderSetUniform4f(Shader * shader, shaderLocationEnum location, float data1, float data2, float data3,
		float data4) {
	((SuperMaximo::Shader*)shader)->setUniform4((SuperMaximo::shaderLocationEnum)location, data1, data2, data3, data4);
}


void shaderSetUniform1i(Shader * shader, shaderLocationEnum location, int data) {
	((SuperMaximo::Shader*)shader)->setUniform1((SuperMaximo::shaderLocationEnum)location, data);
}

void shaderSetUniform2i(Shader * shader, shaderLocationEnum location, int data1, int data2) {
	((SuperMaximo::Shader*)shader)->setUniform2((SuperMaximo::shaderLocationEnum)location, data1, data2);
}

void shaderSetUniform3i(Shader * shader, shaderLocationEnum location, int data1, int data2, int data3) {
	((SuperMaximo::Shader*)shader)->setUniform3((SuperMaximo::shaderLocationEnum)location, data1, data2, data3);
}

void shaderSetUniform4i(Shader * shader, shaderLocationEnum location, int data1, int data2, int data3, int data4) {
	((SuperMaximo::Shader*)shader)->setUniform4((SuperMaximo::shaderLocationEnum)location, data1, data2, data3, data4);
}

}
