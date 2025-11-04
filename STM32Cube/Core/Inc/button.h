/*
 * button.h
 *
 *  Created on: Nov 4, 2025
 *      Author: cthanh
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET
#define number_button 4

void getKeyInput();
int isButtonPressed(int index);

#endif /* INC_BUTTON_H_ */
