#include "sgtl5000.h"


void SGTL5000_WriteRegister(I2C_HandleTypeDef *hi2c, uint16_t reg, uint16_t value) {
    uint8_t data[2];
    data[0] = (uint8_t)(value >> 8);
    data[1] = (uint8_t)(value & 0xFF);

    HAL_I2C_Mem_Write(hi2c, SGTL5000_I2C_ADDRESS, reg, I2C_MEMADD_SIZE_16BIT, data, 2, HAL_MAX_DELAY);
}


void SGTL5000_Init(I2C_HandleTypeDef *hi2c) {
    SGTL5000_WriteRegister(hi2c, CHIP_ANA_POWER, 0x4260);
    SGTL5000_WriteRegister(hi2c, CHIP_LINREG_CTRL, 0x006C);
    SGTL5000_WriteRegister(hi2c, CHIP_REF_CTRL, 0x01FF);
    SGTL5000_WriteRegister(hi2c, CHIP_LINE_OUT_CTRL, 0x031E);
    SGTL5000_WriteRegister(hi2c, CHIP_SHORT_CTRL, 0x1106);
    SGTL5000_WriteRegister(hi2c, CHIP_ANA_CTRL, 0x0004);
    SGTL5000_WriteRegister(hi2c, CHIP_ANA_POWER, 0x6AFF);
    SGTL5000_WriteRegister(hi2c, CHIP_DIG_POWER, 0x0073);
    SGTL5000_WriteRegister(hi2c, CHIP_LINE_OUT_VOL, 0x1111);
    SGTL5000_WriteRegister(hi2c, CHIP_CLK_CTRL, 0x0004);
    SGTL5000_WriteRegister(hi2c, CHIP_I2S_CTRL, 0x0130);
    SGTL5000_WriteRegister(hi2c, CHIP_ADCDAC_CTRL, 0x0000);
    SGTL5000_WriteRegister(hi2c, CHIP_DAC_VOL, 0x3C3C);
}
