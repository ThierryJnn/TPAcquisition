/*
 * pinout.c
 *
 *  Created on: Oct 3, 2023
 *      Author: thier
 */

#include "adc.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "string.h"

typedef struct {
    char name[20];     // Nom de la broche
    char function[20]; // Fonction de la broche
    char state[20];    // État de la broche (par exemple, IN, OUT, HIGH, LOW, etc.)
} PinInfo;

PinInfo pins[] = {
    {"PA0", "GPIO", "IN"},
    {"PA1", "GPIO", "OUT"},
    // Ajoutez d'autres broches et leurs informations ici
};


void pinout() {
    HAL_UART_Transmit(&huart2, "Pinout:\r\n", strlen("Pinout:\r\n"), HAL_MAX_DELAY);

    for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); i++) {
        char message[100];
        snprintf(message, sizeof(message), "Pin %s: Function - %s, State - %s\r\n", pins[i].name, pins[i].function, pins[i].state);
        HAL_UART_Transmit(&huart2, message, strlen(message), HAL_MAX_DELAY);
    }
}

