#include "led.h"
#include "MCP_functions.h"

//Variable globale

static uint8_t reg_GPIOA = 0x12;
static uint8_t reg_GPIOB = 0x13;

// Fonction pour initialiser une LED
void LED_Init(LED *leds) {
    // Initialisation des LEDs sur GPIOA et GPIOB
    for (int i = 0; i < 16; i++) {
        if (i < 8) {
            leds[i].reg = reg_GPIOA;   // LEDs sur GPIOA
            leds[i].pin = i;
        } else {
            leds[i].reg = reg_GPIOB;   // LEDs sur GPIOB
            leds[i].pin = i - 8;       // Pins 0 à 7
        }
        leds[i].state = FALSE; // Par défaut, les LEDs sont éteintes
    }

    // Éteindre toutes les LEDs
    MCP23S17_Write(reg_GPIOA, 0xFF); // GPIOA toutes éteintes
    MCP23S17_Write(reg_GPIOB, 0xFF); // GPIOB toutes éteintes
}

// Fonction pour allumer une LED
void LED_On(LED *led) {
	uint8_t current_state;
	uint8_t new_state;

	current_state = MCP23S17_Read(led->reg);
	new_state = current_state & ~(1 << led->pin);
	MCP23S17_Write(led->reg, new_state);
	led->state = TRUE;
}

void LED_On_ALL(){
	MCP23S17_Write(reg_GPIOA, 0x00);
	MCP23S17_Write(reg_GPIOB, 0X00);
}

// Fonction pour éteindre une LED
void LED_Off(LED *led) {
	uint8_t current_state;
	uint8_t new_state;

	current_state = MCP23S17_Read(led->reg);
	new_state = current_state | (1 << led->pin);
	MCP23S17_Write(led->reg, new_state);
	led->state = FALSE;
}

void LED_Off_ALL(){
	MCP23S17_Write(reg_GPIOA, 0xFF);
	MCP23S17_Write(reg_GPIOB, 0XFF);
}

// Fonction pour basculer l'état d'une LED
void LED_Toggle(LED *led) {
	led->state = !led->state;
	if (led->state) {
		LED_On(led);
	} else {
		LED_Off(led);
	}
}

void chenillard(){
	uint8_t iA=0;
	uint8_t iB=0;

	MCP23S17_Write(reg_GPIOA, 0xFF);
	MCP23S17_Write(reg_GPIOB, 0xff);

	for(iB=0;iB<8;iB++){
		MCP23S17_Write(reg_GPIOB, ~(1<<iB));
		HAL_Delay(100);
	}
	MCP23S17_Write(reg_GPIOB, 0xff);

	for(iA=0;iA<8;iA++){
		MCP23S17_Write(reg_GPIOA, ~(1<<iA));
		HAL_Delay(100);
	}
}
