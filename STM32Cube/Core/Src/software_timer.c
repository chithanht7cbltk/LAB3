/*
 * software_timer.c
 *
 *  Created on: Nov 4, 2025
 *      Author: cthanh
 */

#include "software_timer.h"

#define MAX_TIMER 10

int timer_counter[10] = {0};
int timer_flag[10] = {0};

void setTimer(int index, int duration){
	timer_counter[index] = duration / TIMER_CYCLE;
	timer_flag[index] = 0;
}

int isTimerExpired(int index){
	if(timer_flag[index] == 1){
		return 1;
	}
	return 0;
}

void timerRun(){
	for (int i = 0; i < 7; i++){
		if (timer_counter[i]> 0){
			timer_counter[i]--;
			if (timer_counter[i] <= 0){
				timer_flag[i] = 1;
			}
		}
	}
}


