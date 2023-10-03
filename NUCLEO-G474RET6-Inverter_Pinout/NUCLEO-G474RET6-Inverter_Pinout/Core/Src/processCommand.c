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
#include "pinout.h"
#include "startMotor.h"
#include "stopMotor.h"

void processCommand(char* command) {
  if (strcmp(command, "help") == 0) {
    // Affiche le message d'aide
    HAL_UART_Transmit(&huart2, "Commandes disponibles :\r\n", strlen("Commandes disponibles :\r\n"), HAL_MAX_DELAY);
    HAL_UART_Transmit(&huart2, " - help : Affiche ce message d'aide\r\n", strlen(" - help : Affiche ce message d'aide\r\n"), HAL_MAX_DELAY);
    // Ajoutez d'autres commandes et leurs descriptions ici
    return 0;
  }
  if (strcmp(command, "pinout") == 0) {
	  pinout(); // Appeler la fonction pinout
	  return 0;
  }
  if (strcmp(command, "start") == 0) {
	  startMotor(); // Appeler la fonction startMotor
	  return 0;
  }
  if (strcmp(command, "stop") == 0) {
	  stopMotor(); // Appeler la fonction stopMotor
	  return 0;
    }
  else {
	  HAL_UART_Transmit(&huart2, "Command not found\r\n", strlen("Command not found\r\n"), HAL_MAX_DELAY);
  }
  // Ajoutez d'autres conditions pour d'autres commandes si nécessaire
}
