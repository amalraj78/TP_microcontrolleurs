#ifndef MCP_FUNCTIONS_H
#define MCP_FUNCTIONS_H

#include "main.h"

void MCP23S17_Init(void);
void MCP23S17_Write(uint8_t reg, uint8_t value);
uint8_t MCP23S17_Read(uint8_t reg);


#endif
