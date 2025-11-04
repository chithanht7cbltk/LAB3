/*
 * led7_segment.c
 *
 *  Created on: Nov 4, 2025
 *      Author: cthanh
 */

#include "led7_segment.h"

char seg[10] =
	{
		0x40,
		0x79,
		0x24,
		0x30,
		0x19,
		0x12,
		0x02,
		0x78,
		0x00,
		0x10};

void display_number_vertical(int number)
{
	char code = seg[number];

	// Kiem tra bit tuong ung SEG cua so can hien thi neu = 1 thi SEG OFF
	HAL_GPIO_WritePin(SEG0_A_GPIO_Port, SEG0_A_Pin, (code & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG0_B_GPIO_Port, SEG0_B_Pin, (code & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG0_C_GPIO_Port, SEG0_C_Pin, (code & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG0_D_GPIO_Port, SEG0_D_Pin, (code & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG0_E_GPIO_Port, SEG0_E_Pin, (code & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG0_F_GPIO_Port, SEG0_F_Pin, (code & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG0_G_GPIO_Port, SEG0_G_Pin, (code & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void display_number_horizontal(int number)
{
	char code = seg[number];

	// Kiem tra bit tuong ung SEG cua so can hien thi neu = 1 thi SEG OFF
	HAL_GPIO_WritePin(SEG1_A_GPIO_Port, SEG1_A_Pin, (code & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, (code & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG1_C_GPIO_Port, SEG1_C_Pin, (code & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG1_D_GPIO_Port, SEG1_D_Pin, (code & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG1_E_GPIO_Port, SEG1_E_Pin, (code & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG1_F_GPIO_Port, SEG1_F_Pin, (code & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG1_G_GPIO_Port, SEG1_G_Pin, (code & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void enable_horizontal(int index)
{
	if (index == 0)
	{
		HAL_GPIO_WritePin(GPIOA, EN2_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, EN3_Pin, SET);
	}
	if (index == 1)
	{
		HAL_GPIO_WritePin(GPIOA, EN3_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, EN2_Pin, SET);
	}
}

void enable_vertical(int index)
{
	if (index == 0)
	{
		HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, EN1_Pin, SET);
	}
	if (index == 1)
	{
		HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, EN0_Pin, SET);
	}
}

void clear_all_7seg()
{
	HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin | EN3_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, SEG0_A_Pin | SEG0_B_Pin | SEG0_C_Pin | SEG0_D_Pin | SEG0_E_Pin | SEG0_F_Pin | SEG0_G_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, SEG1_A_Pin | SEG1_B_Pin | SEG1_C_Pin | SEG1_D_Pin | SEG1_E_Pin | SEG1_F_Pin | SEG1_G_Pin, SET);
}

void update_7seg_horizontal(int index_buffer_horizontal)
{
	switch (index_buffer_horizontal)
	{
	case 0:
		enable_horizontal(0);
		display_number_horizontal(led_buffer_horizontal[0]);
		break;
	case 1:
		enable_horizontal(1);
		display_number_horizontal(led_buffer_horizontal[1]);
		break;
	default:
		break;
	}
}

void update_7seg_vertical(int index_buffer_vertical)
{
	switch (index_buffer_vertical)
	{
	case 0:
		enable_vertical(0);
		display_number_vertical(led_buffer_vertical[0]);
		break;
	case 1:
		enable_vertical(1);
		display_number_vertical(led_buffer_vertical[1]);
		break;
	default:
		break;
	}
}

void update_buffer_horizontal()
{
	led_buffer_horizontal[0] = counter_horizontal / 10;
	led_buffer_horizontal[1] = counter_horizontal % 10;
}

void update_buffer_vertical()
{
	led_buffer_vertical[0] = counter_vertical / 10;
	led_buffer_vertical[1] = counter_vertical % 10;
}
