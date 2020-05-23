/*
 * @file  			: API_LED.cpp
 * @author			: huzeyfe piroglu
 * @date  			: 23.05.2020
 * @Keil  			: ARM MDK V5.30
 * @MCU   			: STM32F051K6T6 
 * @CubeMX			: STM32CubeMX V5.3.0
 * @mail   			: a.huzeyfepiroglu@gmail.com
 * @github 			: https://github.com/huzeyfepiroglu
 *
 * @Description :
 *
 * In embedded systems, the use of the C programming language is often greater.
 * However, the number of C++ libraries has exceeded the number of c libraries with the use of Arduino.
 * While C libraries are running in software written in C++, C++ libraries do not work in c based software.
 * At this point, I think it is more advantageous to write c ++ based software to develop the project faster.
 * This work is my first C++ based project.
 */

#ifndef _LEDCPP_H
#define _LEDCPP_H
#include "stm32f0xx_hal.h"

class CLed
{
  GPIO_TypeDef* _port;                                      //GPIOA,GPIOB....
  uint16_t _pin;                                            //GPIO_PIN_0,GPIO_PIN_1....
  uint16_t _toggleTime;                                     //Toggle time in ms
  uint16_t counter;                                         //Toggle time counter

public:
	
  CLed(GPIO_TypeDef* port,uint16_t pin,uint16_t toggleTime); //constructor
  void on();    //turn on LED
  void off(); //turn off LED
  void toggle();            //toggle LED
	
	void runToggle();                                         //run toggling LED from system tick every 1ms	
};

#endif

