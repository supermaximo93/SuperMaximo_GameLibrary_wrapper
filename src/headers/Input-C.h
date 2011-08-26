/*
 * Input-C.h
 *
 *  Created on: 26 Aug 2011
 *      Author: Max Foster
 */

#ifndef INPUTC_H_
#define INPUTC_H_

#ifdef __cplusplus
extern "C" {
#endif

enum dpadEnum {
	DPAD_UP = 0,
	DPAD_DOWN,
	DPAD_LEFT,
	DPAD_RIGHT
};

void initInput();
void quitInput();

int keyPressed(unsigned code);

void setMousePosition(int x, int y);
void hideCursor();
void showCursor();
int mouseX();
int mouseY();
int mouseLeft();
int mouseRight();
int mouseMiddle();
int mouseOther();
int mouseWheelUp();
int mouseWheelDown();

int closeClicked();

int joystickCount();
int joystickButtonPressed(unsigned code, unsigned controllerId);
int joystickDpadPressed(enum dpadEnum code, unsigned controllerId);
int joystickAxisValue(unsigned axis, unsigned controllerId);

void resetEvents();

#ifdef __cplusplus
}
#endif

#endif /* INPUTC_H_ */
