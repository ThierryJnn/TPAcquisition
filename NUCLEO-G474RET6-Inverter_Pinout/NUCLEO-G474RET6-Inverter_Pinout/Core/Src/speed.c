/*
 * speed.c
 *
 *  Created on: Oct 20, 2023
 *      Author: thier
 */

#include "adc.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "string.h"

extern int Power;
void speed(int digit1, int digit2, int digit3, int digit4) {
	if (Power==0){
		HAL_UART_Transmit(&huart2, "Moteur éteint\r\n", strlen("Moteur éteint\r\n"), HAL_MAX_DELAY);
		return 0;
	}

    int speed = digit1 * 1000 + digit2 * 100 + digit3 * 10 + digit4;
    if (speed>1023) {
    	speed=1023;
    	HAL_UART_Transmit(&huart2, "Vitesse abaissée au max: 1023\r\n", strlen("Vitesse abaissée au max: 1023\r\n"), HAL_MAX_DELAY);
    }
    int rapcycl= speed/1023*100;
    char message[30];
    snprintf(message, sizeof(message), "Speed set to: %d%% \r\n", rapcycl);
    HAL_UART_Transmit(&huart2, message, strlen(message), HAL_MAX_DELAY);
}
