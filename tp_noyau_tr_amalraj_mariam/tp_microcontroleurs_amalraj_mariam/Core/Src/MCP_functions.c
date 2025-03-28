#include "MCP_functions.h"

extern SPI_HandleTypeDef hspi3;

void MCP23S17_Init(void) {
    HAL_GPIO_WritePin(VU_nCS_GPIO_Port, VU_nCS_Pin, GPIO_PIN_RESET);
    MCP23S17_Write(0x00, 0x00);
    MCP23S17_Write(0x01, 0x00);
    HAL_GPIO_WritePin(VU_nCS_GPIO_Port, VU_nCS_Pin, GPIO_PIN_SET);
}

void MCP23S17_Write(uint8_t reg, uint8_t value) {
    uint8_t data[3] = {0x40, reg, value};
    HAL_GPIO_WritePin(VU_nCS_GPIO_Port, VU_nCS_Pin, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi3, data, sizeof(data), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(VU_nCS_GPIO_Port, VU_nCS_Pin, GPIO_PIN_SET);
}


uint8_t MCP23S17_Read(uint8_t reg) {
    uint8_t data[2];
    uint8_t value;

    data[0] = 0x41;
    data[1] = reg;


    HAL_GPIO_WritePin(VU_nCS_GPIO_Port, VU_nCS_Pin, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi3, data, 2, HAL_MAX_DELAY);
    HAL_SPI_Receive(&hspi3, &value, 1, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(VU_nCS_GPIO_Port, VU_nCS_Pin, GPIO_PIN_SET);
    return value;
}


