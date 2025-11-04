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

int TimerForPressKey[4];

int button_flag[number_button] = {0};
int button_long_pressed_flag[3];

int isButtonPressed(int index)
{
	if (button_flag[index] == 1)
	{
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

int isButtonLongPressed(int index){
    if(button_long_pressed_flag[index] == 1){
        button_long_pressed_flag[index] = 0;
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
	for(int i=0; i<=3; i++){
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		if (i == 1)
			KeyReg2[1] = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
		if (i == 2)
			KeyReg2[2] = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);
		if (i == 3)
			KeyReg2[3] = HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin);


		// nếu ổn định 3 lần đọc
		if((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])){
			if(KeyReg3[i] != KeyReg2[i]){          // trạng thái thay đổi
				KeyReg3[i] = KeyReg2[i];
				if(KeyReg2[i] == PRESSED_STATE){   // nút vừa nhấn
					button_flag[i] = 1;            // nhấn ngắn
					TimerForPressKey[i] = LONGPRESS_START; // khởi động đếm 1s
					button_long_pressed_flag[i] = 0;
				} else {                           // nút vừa thả
					TimerForPressKey[i] = 0;
					button_long_pressed_flag[i] = 0;
				}
			} else {                               // trạng thái không đổi
				if(KeyReg2[i] == PRESSED_STATE){   // vẫn đang nhấn
					if(TimerForPressKey[i] > 0){
						TimerForPressKey[i]--;
						if(TimerForPressKey[i] == 0){
							// đạt ngưỡng long-press hoặc lặp
							button_long_pressed_flag[i] = 1;
							TimerForPressKey[i] = LONGPRESS_REPEAT; // tiếp tục lặp 0.5s
						}
					}
				}
			}
		}
	}
}

