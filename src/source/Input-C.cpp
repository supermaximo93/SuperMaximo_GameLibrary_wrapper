/*
 * Input-C.cpp
 *
 *  Created on: 26 Aug 2011
 *      Author: Max Foster
 */

#include "../SuperMaximo_GameLibrary/headers/Input.h"

#include "../headers/Input-C.h"

extern "C" {

void initInput() {
	SuperMaximo::initInput();
}

void quitInput() {
	SuperMaximo::quitInput();
}

int keyPressed(unsigned code) {
	return SuperMaximo::keyPressed(code);
}

void setMousePosition(int x, int y) {
	SuperMaximo::setMousePosition(x, y);
}

void hideCursor() {
	SuperMaximo::hideCursor();
}

void showCursor() {
	SuperMaximo::showCursor();
}

int mouseX() {
	return SuperMaximo::mouseX();
}

int mouseY() {
	return SuperMaximo::mouseY();
}

int mouseLeft() {
	return SuperMaximo::mouseLeft();
}

int mouseRight() {
	return SuperMaximo::mouseRight();
}

int mouseMiddle() {
	return SuperMaximo::mouseMiddle();
}

int mouseOther() {
	return SuperMaximo::mouseOther();
}

int mouseWheelUp() {
	return SuperMaximo::mouseWheelUp();
}

int mouseWheelDown() {
	return SuperMaximo::mouseWheelDown();
}

int closeClicked() {
	return SuperMaximo::closeClicked();
}

int joystickCount() {
	return SuperMaximo::joystickCount();
}

int joystickButtonPressed(unsigned code, unsigned controllerId) {
	return SuperMaximo::joystickButtonPressed(code, controllerId);
}

int joystickDpadPressed(enum dpadEnum code, unsigned controllerId) {
	return SuperMaximo::joystickDpadPressed((SuperMaximo::dpadEnum)code, controllerId);
}

int joystickAxisValue(unsigned axis, unsigned controllerId) {
	return SuperMaximo::joystickAxisValue(axis, controllerId);
}

void resetEvents() {
	SuperMaximo::resetEvents();
}

}
