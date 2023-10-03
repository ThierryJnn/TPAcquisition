/*
 * processCommand.c
 *
 *  Created on: Oct 3, 2023
 *      Author: thier
 */

#include "adc.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "string.h"

void processCommand(char* command) {
  if (strcmp(command, "help") == 0) {
    // Affiche le message d'aide
    HAL_UART_Transmit(&huart2, "Commandes disponibles :\r\n", strlen("Commandes disponibles :\r\n"), HAL_MAX_DELAY);
    HAL_UART_Transmit(&huart2, " - help : Affiche ce message d'aide\r\n", strlen(" - help : Affiche ce message d'aide\r\n"), HAL_MAX_DELAY);
    // Ajoutez d'autres commandes et leurs descriptions ici
  }
  // Ajoutez d'autres conditions pour d'autres commandes si nécessaire
}