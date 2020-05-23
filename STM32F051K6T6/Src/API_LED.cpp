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
 
#include "API_LED.h"

 CLed::CLed(GPIO_TypeDef* port,uint16_t pin,uint16_t toggleTime)
{
  _port=port;
  _pin=pin;
  _toggleTime=toggleTime;
  counter=0; 
  off();	
}

void CLed::on()
{
HAL_GPIO_WritePin(_port,_pin,GPIO_PIN_SET);
}

void CLed::off()
{
HAL_GPIO_WritePin(_port,_pin,GPIO_PIN_RESET);
}

void CLed::toggle()
{
HAL_GPIO_TogglePin(_port,_pin);
}

void CLed::runToggle()
{
  if(++counter>=_toggleTime)
  {
    counter=0;
    toggle();
  }
}

