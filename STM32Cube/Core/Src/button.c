/*
 * button.c
 *
 *  Created on: Nov 4, 2025
 *      Author: HP
 */

#include "button.h"

int KeyReg0[number_button] = {NORMAL_STATE};
int KeyReg1[number_button] = {NORMAL_STATE};
int KeyReg2[number_button] = {NORMAL_STATE};

int KeyReg3[number_button] = {NORMAL_STATE};
int TimerForPressKey = 200;

int button_flag[number_button] = {0};

int isButtonPressed(int index)
{
	if (button_flag[index] == 1)
	{
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

void subProcess(int index)
{
	button_flag[index] = 1;
}

void getKeyInput()
{
	for (int i = 1; i <= 3; i++)
	{
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];

		if (i == 1)
			KeyReg2[1] = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
		if (i == 2)
			KeyReg2[2] = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);
		if (i == 3)
			KeyReg2[3] = HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin);

		if ((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i]))
		{
			if (KeyReg3[i] != KeyReg2[i])
			{
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg2[i] == PRESSED_STATE)
				{
					// TODO
					subProcess(i);
					TimerForPressKey = 200;
				}
			}
			else
			{
				TimerForPressKey--;
				if (TimerForPressKey == 0)
				{
					//				if (KeyReg2[i] == PRESSED_STATE)
					//				{
					//					//TODO
					//					subProcess();
					//				}
					//				TimerForPressKey = 200;
					KeyReg3[i] = NORMAL_STATE;
				}
			}
		}
	}
}

