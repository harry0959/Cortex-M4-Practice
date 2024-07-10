/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#define ALIAS_BASE 0x22000000U
#define BITBAND_BASE 0x20000000U

//Change 7th bit of 0x20000200 (clearing 7th bit position)
int main(void)
{
	//pointer point to 0x20000200
    uint8_t *ptr = (uint8_t *)0x20000200;

    //first, let the value of 0x20000200 is FF
    *ptr = 0xff;

    //normal way to change 7th value
    //clearing 7th bit position
    *ptr &= ~(1 << 7);

    //reset to 0xFF
    *ptr = 0xff;

    //bit band method
    uint8_t *alias_addr = (uint8_t*) (ALIAS_BASE + (32 * (0x20000200 - BITBAND_BASE)) + 7*4);
   //clearing 7th bit of 0x20000200
    *alias_addr = 0;


	for(;;);
}
