/*
 * fsm_setting.c
 *
 *  Created on: Nov 4, 2025
 *      Author: cthanh
 */

#include "fsm_setting.h"

void fsm_setting_run()
{
	switch (status_horizontal_traffic)
	{
	case INIT_MODE:
		status_horizontal_traffic = MODE2;
		clear_all();
		setTimer(1, 10000); // đợi nút 1 chuyển mode
		setTimer(2, 250);
		setTimer(3, 250);

		set_tmp_duration();

		break;
	case MODE1:
		if (timer_flag[0] == 1)
		{
			status_horizontal_traffic = INIT;
			status_vertical_traffic = INIT;
		}
		if (isButtonPressed(1) == 1)
		{
			status_horizontal_traffic = MODE2;
			setTimer(1, 10000); // đợi nút 1 chuyển mode
			setTimer(2, 250);
			setTimer(3, 250);
		}
		set_tmp_duration();

		break;
	case MODE2:
		enable_vertical(0);
		display_number_vertical(2);
		counter_horizontal = red_duration_tmp;
		update_buffer_horizontal();

		if (timer_flag[3] == 1)
		{
			update_7seg_horizontal(index_buffer_horizontal++);
			if (index_buffer_horizontal >= 2)
				index_buffer_horizontal = 0;
			setTimer(3, 250);
		}

		if (timer_flag[2] == 1)
		{
			custom_red_mode();
			setTimer(2, 250);
		}
		if (isButtonPressed(1) == 1)
		{
			status_horizontal_traffic = MODE3;
			setTimer(1, 10000);
		}
		if (isButtonPressed(2) == 1)
		{
			red_duration_tmp++;
			if (red_duration_tmp > 99)
				red_duration_tmp = 0;
			setTimer(1, 10000);
		}

		// auto tăng liên tục khi giữ >1s (mỗi 0.5s)
		if(isButtonLongPressed(2)){
		    red_duration_tmp++;
		    if(red_duration_tmp > 99)
		    	red_duration_tmp = 0;
		}

		if (isButtonPressed(3) == 1)
		{
			red_duration = red_duration_tmp;
			status_horizontal_traffic = MODE1;
			clear_all();
			setTimer(0, 1000);
		}
		if (timer_flag[1] == 1)
		{
			status_horizontal_traffic = MODE1;
		}

		break;
	case MODE3:
		enable_vertical(0);
		display_number_vertical(3);
		counter_horizontal = green_duration_tmp;
		update_buffer_horizontal();

		if (timer_flag[3] == 1)
		{
			update_7seg_horizontal(index_buffer_horizontal++);
			if (index_buffer_horizontal >= 2)
				index_buffer_horizontal = 0;
			setTimer(3, 250);
		}

		if (timer_flag[2] == 1)
		{
			custom_green_mode();
			setTimer(2, 250);
		}
		if (isButtonPressed(1) == 1)
		{
			status_horizontal_traffic = MODE4;
			setTimer(1, 10000);
		}
		if (isButtonPressed(2) == 1)
		{
			// Tang thoi gian green
			green_duration_tmp++;
			if (green_duration_tmp > 99)
				green_duration_tmp = 0;
		}

		// auto tăng liên tục khi giữ >1s (mỗi 0.5s)
		if(isButtonLongPressed(2)){
			green_duration_tmp++;
			if(green_duration_tmp > 99)
				green_duration_tmp = 0;
		}

		if (isButtonPressed(3) == 1)
		{
			green_duration = green_duration_tmp;
			status_horizontal_traffic = MODE1;
			clear_all();
			setTimer(0, 1000);
		}
		if (timer_flag[1] == 1)
		{
			status_horizontal_traffic = MODE1;
		}

		break;
	case MODE4:
		enable_vertical(0);
		display_number_vertical(4);
		counter_horizontal = yellow_duration_tmp;
		update_buffer_horizontal();

		if (timer_flag[3] == 1)
		{
			update_7seg_horizontal(index_buffer_horizontal++);
			if (index_buffer_horizontal >= 2)
				index_buffer_horizontal = 0;
			setTimer(3, 250);
		}

		if (timer_flag[2] == 1)
		{
			custom_yellow_mode();
			setTimer(2, 250);
		}
		if (isButtonPressed(1) == 1)
		{
			status_horizontal_traffic = MODE1;
			clear_all();
			setTimer(0, 1000);
		}
		if (isButtonPressed(2) == 1)
		{
			// Tang thoi gian yellow
			yellow_duration_tmp++;
			if (yellow_duration_tmp > 99)
				yellow_duration_tmp = 0;
		}

		// auto tăng liên tục khi giữ >1s (mỗi 0.5s)
		if(isButtonLongPressed(2)){
			yellow_duration_tmp++;
			if(yellow_duration_tmp > 99)
				yellow_duration_tmp = 0;
		}

		if (isButtonPressed(3) == 1)
		{
			yellow_duration = yellow_duration_tmp;
			status_horizontal_traffic = MODE1;
			clear_all();
			setTimer(0, 1000);
		}
		if (timer_flag[1] == 1)
		{
			status_horizontal_traffic = MODE1;
		}

		break;
	default:
		break;
	}
}

