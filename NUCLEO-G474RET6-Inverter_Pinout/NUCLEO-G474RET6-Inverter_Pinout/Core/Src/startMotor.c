/*
 * startMotor.c
 *
 *  Created on: Oct 3, 2023
 *      Author: thier
 */

#include "adc.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "string.h"

void startMotor() {
    // Activez l'étage de puissance du moteur (code pour activer le moteur)

    // Affichez le message "Power ON" dans la console
    HAL_UART_Transmit(&huart2, "Power ON\r\n", strlen("Power ON\r\n"), HAL_MAX_DELAY);
}
