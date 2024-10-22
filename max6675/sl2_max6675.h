#ifndef SL2_MAX6675_H
#define SL2_MAX6675_H

#include "sl2_spi.h"
#include "sl2_gpio.h"
#include "sl2_stm32g071_config.h"


typedef struct {
    SL2_SPI_t *spi;
    SL2_GPIO_t cs;
} SL2_MAX6675_t;


void SL2_MAX6675_Init(SL2_MAX6675_t *max6675, SL2_SPI_t *spi, SL2_GPIO_t cs) {
    max6675->spi = spi;
    max6675->cs = cs;

    SL2_GPIO_InitDigitalOutput(&max6675->cs);
    SL2_GPIO_DigitalWrite(&max6675->cs, 1);
}

uint16_t SL2_MAX6675_ReadRAW(SL2_MAX6675_t *max6675) {
    SL2_GPIO_DigitalWrite(&max6675->cs, 0);

    uint16_t data = 0;
    SL2_SPI_Read(max6675->spi, 2, (uint8_t *)&data);

    SL2_GPIO_DigitalWrite(&max6675->cs, 1);

    return data;
}

void SL2_MAX6675_ForceConversion(SL2_MAX6675_t *max6675) {
    SL2_GPIO_DigitalWrite(&max6675->cs, 0);

    LL_mDelay(1);

    SL2_GPIO_DigitalWrite(&max6675->cs, 1);
}

#endif // SL2_MAX6675_H