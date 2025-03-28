#ifndef LED_H
#define LED_H
#define FALSE 0
#define TRUE  1

#include "main.h"

// Structure pour représenter une LED
typedef struct {
    uint8_t reg;       // Registre GPIO (GPIOA ou GPIOB)
    uint8_t pin;       // Pin de la LED (0 à 7)
    uint8_t state;        // État de la LED (true = allumée, false = éteinte)
} LED;



// Prototypes des fonctions
void LED_Init(LED *leds);
void LED_On(LED *led);
void LED_Off(LED *led);
void LED_Toggle(LED *led);
void LED_On_ALL(void);
void LED_Off_ALL(void);
void chenillard(void);

#endif
