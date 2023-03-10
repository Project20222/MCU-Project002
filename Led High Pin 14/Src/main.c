/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
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

int main(void)
{
	//Setting all Registers with the base address...
	//Address of RCC-(RCC_AHB1ENR)
	uint32_t  *pRccCtrlReg=(uint32_t *)0x40023830;

	//Address of GPIOD port mode register to configure as output mode
	uint32_t  *pGPIODModeReg=(uint32_t *)0x40020C00;

	//Address of GPIOD o/p Data Register to write the output
	uint32_t  *pGPIODOutReg=(uint32_t *)0x40020C14;

	//Steps for LED ON
	//Step1:setting the 3 bit to 1 ie high
	*pRccCtrlReg=*pRccCtrlReg | 0X08;

	//Step 2:
	//a.Clearing all the bits with 1 except 29 &28 with 0
	*pGPIODModeReg= *pGPIODModeReg & 0XCFFFFFFF;
	//b.Setting all the bits with 0's except 28 th 1 bcoz it is in output mode...(using OR operations)
	*pGPIODModeReg=*pGPIODModeReg |0X10000000;

	//Step3.Configure the GPIOD output data register with the 1 ie,high so the LED wil be on.Activate the 12 pin
	*pGPIODOutReg=*pGPIODOutReg | 0X4000;
	while(1);







}
