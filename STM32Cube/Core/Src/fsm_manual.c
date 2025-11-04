/*
 * fsm_manual.c
 *
 *  Created on: Nov 4, 2025
 *      Author: HP
 */

//#include "fsm_manual.h"
//
//void fsm_manual_run()
//{
//	switch (status)
//	{
//		case MAN_RED:
//			RED2_ON();
//
//			if (isButtonPressed(1) == 1)
//			{
//				status = MAN_GREEN;
//				setTimer(0, 10000);
//			}
//
//			if(timer_flag[0] == 1)
//			{
//				status = AUTO_RED;
//				setTimer(0, 5000);
//			}
//			break;
//		case MAN_GREEN:
//			GREEN2_ON();
//
//			if (isButtonPressed(1) == 1)
//			{
//				status = MAN_YELLOW;
//				setTimer(0, 10000);
//			}
//
//			if (timer_flag[0] == 1)
//			{
//				status = AUTO_GREEN;
//				setTimer(0, 3000);
//			}
//			break;
//		case MAN_YELLOW:
//			YELLOW2_ON();
//
//			if (isButtonPressed(1) == 1)
//			{
//				status = MAN_RED;
//				setTimer(0, 10000);
//			}
//
//			if (timer_flag[0] == 1)
//			{
//				status = AUTO_YELLOW;
//				setTimer(0, 2000);
//			}
//			break;
//		default:
//			break;
//	}
//}

