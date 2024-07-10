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

#include<stdio.h>
#include<stdint.h>


int main(void)
{
	__asm("SVC #26");

	uint32_t data;
	__asm volatile("MOV %0, R0":"=r"(data)::);

	printf("data:%ld \n", data);
	/* Loop forever */
	for(;;);
}


__attribute__((naked)) void SVC_Handler(void)
{
	__asm("MRS R0, MSP");
	__asm("B SVC_Handler_c");
}

void SVC_Handler_c(uint32_t *pBaseOfStackFrame)
{
	printf("in SVC handler\n");

	//why set 8 bit? because the opcode is 8 bit(easy access and manipulation of individual byte)
	uint8_t *pReturn_addr = (uint8_t*)pBaseOfStackFrame[6];
	pReturn_addr-=2;

	uint8_t svc_number = *pReturn_addr;
	printf("SVC number %d\n", svc_number);

	svc_number -= 4;

	//modify stack frame -> effect unstacking
	pBaseOfStackFrame[0] = svc_number;


}