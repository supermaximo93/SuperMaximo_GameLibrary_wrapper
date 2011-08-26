/*
 * Shader-C.h
 *
 *  Created on: 26 Aug 2011
 *      Author: Max Foster
 */

#ifndef SHADERC_H_
#define SHADERC_H_

#include "Display-C.h"

#ifdef __cplusplus

class Shader;
extern "C" {

#endif

enum shaderAttributeEnum {
	VERTEX_ATTRIBUTE = 0,
	NORMAL_ATTRIBUTE,
	COLOR0_ATTRIBUTE,
	COLOR1_ATTRIBUTE,
	COLOR2_ATTRIBUTE,
	TEXTURE0_ATTRIBUTE,
	EXTRA0_ATTRIBUTE,
	EXTRA1_ATTRIBUTE,
	EXTRA2_ATTRIBUTE,
	EXTRA3_ATTRIBUTE,
	EXTRA4_ATTRIBUTE
};

enum shaderLocationEnum {
	MODELVIEW_LOCATION = 0,
	PROJECTION_LOCATION,
	TEXSAMPLER_LOCATION,
	EXTRA0_LOCATION,
	EXTRA1_LOCATION,
	EXTRA2_LOCATION,
	EXTRA3_LOCATION,
	EXTRA4_LOCATION,
	EXTRA5_LOCATION,
	EXTRA6_LOCATION,
	EXTRA7_LOCATION,
	EXTRA8_LOCATION,
	EXTRA9_LOCATION,
	TEXCOMPAT_LOCATION,
	SHADER_LOCATION_ENUM_COUNT
};

Shader * shaderNew(const char * newName, const char * vertexShaderFile, const char * fragmentShaderFile,
		unsigned count, int * enums, const char ** attributeNames);
void shaderDelete(Shader * shader);

const char * shaderName(Shader * shader);
void shaderBind(Shader * shader);
void shaderUse(Shader * shader);
unsigned shaderProgram(Shader * shader);
unsigned shaderSetUniformLocation(Shader * shader, enum shaderLocationEnum dstLocation, const char * locationName);
unsigned shaderUniformLocation(Shader * shader, enum shaderLocationEnum location);

void shaderSetUniform1fa(Shader * shader, enum shaderLocationEnum location, float * data, unsigned count);
void shaderSetUniform2fa(Shader * shader, enum shaderLocationEnum location, float * data, unsigned count);
void shaderSetUniform3fa(Shader * shader, enum shaderLocationEnum location, float * data, unsigned count);
void shaderSetUniform4fa(Shader * shader, enum shaderLocationEnum location, float * data, unsigned count);

void shaderSetUniform9fa(Shader * shader, enum shaderLocationEnum location, float * data, unsigned count);
void shaderSetUniform16fa(Shader * shader, enum shaderLocationEnum location, float * data, unsigned count);

void shaderSetUniform1ia(Shader * shader, enum shaderLocationEnum location, int * data, unsigned count);
void shaderSetUniform2ia(Shader * shader, enum shaderLocationEnum location, int * data, unsigned count);
void shaderSetUniform3ia(Shader * shader, enum shaderLocationEnum location, int * data, unsigned count);
void shaderSetUniform4ia(Shader * shader, enum shaderLocationEnum location, int * data, unsigned count);

void shaderSetUniform1f(Shader * shader, enum shaderLocationEnum location, float data);
void shaderSetUniform2f(Shader * shader, enum shaderLocationEnum location, float data1, float data2);
void shaderSetUniform3f(Shader * shader, enum shaderLocationEnum location, float data1, float data2, float data3);
void shaderSetUniform4f(Shader * shader, enum shaderLocationEnum location, float data1, float data2, float data3,
		float data4);

void shaderSetUniform1i(Shader * shader, enum shaderLocationEnum location, int data);
void shaderSetUniform2i(Shader * shader, enum shaderLocationEnum location, int data1, int data2);
void shaderSetUniform3i(Shader * shader, enum shaderLocationEnum location, int data1, int data2, int data3);
void shaderSetUniform4i(Shader * shader, enum shaderLocationEnum location, int data1, int data2, int data3, int data4);

#ifdef __cplusplus
}
#endif

#endif /* SHADERC_H_ */
