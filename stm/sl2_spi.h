
#ifndef SL2_SPI_H
#define SL2_SPI_H

#include "sl2_stm32g071_config.h"

#if defined(STM32G071xx)
    #include "stm32g0xx_ll_spi.h"
#else
    #error "Library not compatible with selected device (STM32G071xx) - at least for now ;) "
#endif


typedef struct {
    SPI_TypeDef *spi;
} SL2_SPI_t;


typedef enum {
    SL2_SPI_MODE_MASTER = LL_SPI_MODE_MASTER,
    SL2_SPI_MODE_SLAVE = LL_SPI_MODE_SLAVE
} SL2_SPI_Mode_t;

typedef enum {
    SL2_SPI_POLARITY_LOW = LL_SPI_POLARITY_LOW,
    SL2_SPI_POLARITY_HIGH = LL_SPI_POLARITY_HIGH
} SL2_SPI_Polarity_t;

typedef enum {
    SL2_SPI_PHASE_1EDGE = LL_SPI_PHASE_1EDGE,
    SL2_SPI_PHASE_2EDGE = LL_SPI_PHASE_2EDGE
} SL2_SPI_Phase_t;

typedef enum {
    SL2_SPI_MSB_FIRST = LL_SPI_MSB_FIRST,
    SL2_SPI_LSB_FIRST = LL_SPI_LSB_FIRST
} SL2_SPI_BitOrder_t;

typedef enum {
    SL2_SPI_BAUDRATEPRESCALER_DIV2 = LL_SPI_BAUDRATEPRESCALER_DIV2,
    SL2_SPI_BAUDRATEPRESCALER_DIV4 = LL_SPI_BAUDRATEPRESCALER_DIV4,
    SL2_SPI_BAUDRATEPRESCALER_DIV8 = LL_SPI_BAUDRATEPRESCALER_DIV8,
    SL2_SPI_BAUDRATEPRESCALER_DIV16 = LL_SPI_BAUDRATEPRESCALER_DIV16,
    SL2_SPI_BAUDRATEPRESCALER_DIV32 = LL_SPI_BAUDRATEPRESCALER_DIV32,
    SL2_SPI_BAUDRATEPRESCALER_DIV64 = LL_SPI_BAUDRATEPRESCALER_DIV64,
    SL2_SPI_BAUDRATEPRESCALER_DIV128 = LL_SPI_BAUDRATEPRESCALER_DIV128,
    SL2_SPI_BAUDRATEPRESCALER_DIV256 = LL_SPI_BAUDRATEPRESCALER_DIV256
} SL2_SPI_BaudRatePrescaler_t;


void SL2_SPI_Init(SL2_SPI_t *spi, SPI_TypeDef *spiInstance, SL2_SPI_PinMapping_t sck, SL2_SPI_PinMapping_t miso, SL2_SPI_PinMapping_t mosi) {
    spi->spi = spiInstance;

    /* GPIO Configuration */

    LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = sck.pin;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate = sck.af;
    LL_GPIO_Init(sck.port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = miso.pin;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate = miso.af;
    LL_GPIO_Init(miso.port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = mosi.pin;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate = mosi.af;
    LL_GPIO_Init(mosi.port, &GPIO_InitStruct);


    /* SPI Configuration */

    LL_SPI_InitTypeDef LL_SPI_InitStruct = {0};

    LL_SPI_InitStruct.TransferDirection = LL_SPI_FULL_DUPLEX;
    LL_SPI_InitStruct.Mode = LL_SPI_MODE_MASTER;
    LL_SPI_InitStruct.DataWidth = LL_SPI_DATAWIDTH_8BIT;
    LL_SPI_InitStruct.ClockPolarity = LL_SPI_POLARITY_LOW;
    LL_SPI_InitStruct.ClockPhase = LL_SPI_PHASE_1EDGE;
    LL_SPI_InitStruct.NSS = LL_SPI_NSS_SOFT;
    LL_SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV8;
    LL_SPI_InitStruct.BitOrder = LL_SPI_MSB_FIRST;
    LL_SPI_InitStruct.CRCCalculation = LL_SPI_CRCCALCULATION_DISABLE;
    LL_SPI_InitStruct.CRCPoly = 7;

    LL_SPI_SetStandard(spi->spi, LL_SPI_PROTOCOL_MOTOROLA);
    LL_SPI_DisableNSSPulseMgt(spi->spi);

    LL_SPI_Init(spi->spi, &LL_SPI_InitStruct);
    LL_SPI_Enable(spi->spi);
}


void SL2_SPI_SetMode(SL2_SPI_t *spi, SL2_SPI_Mode_t mode) {
    LL_SPI_SetMode(spi->spi, mode);
}

void SL2_SPI_SetPolPhase(SL2_SPI_t *spi, SL2_SPI_Polarity_t polarity, SL2_SPI_Phase_t phase) {
    LL_SPI_SetClockPolarity(spi->spi, polarity);
    LL_SPI_SetClockPhase(spi->spi, phase);
}

void SL2_SPI_SetBitOrder(SL2_SPI_t *spi, SL2_SPI_BitOrder_t bitOrder) {
    LL_SPI_SetTransferBitOrder(spi->spi, bitOrder);
}

void SL2_SPI_SetClockPrescaler(SL2_SPI_t *spi, SL2_SPI_BaudRatePrescaler_t prescaler) {
    LL_SPI_SetBaudRatePrescaler(spi->spi, prescaler);
}


uint8_t SL2_SPI_Transmit_8bit(SL2_SPI_t *spi, uint8_t data) {
    LL_SPI_TransmitData8(spi->spi, data);
    while (!LL_SPI_IsActiveFlag_TXE(spi->spi));
    while (!LL_SPI_IsActiveFlag_RXNE(spi->spi));
    return LL_SPI_ReceiveData8(spi->spi);
}

void SL2_SPI_WriteRead(SL2_SPI_t *spi, uint8_t bytes, uint8_t *inData, uint8_t *outData) {
    for (uint8_t i = 0; i < bytes; i++) {
        inData[i] = SL2_SPI_Transmit_8bit(spi, outData[i]);
    }
}

void SL2_SPI_Write(SL2_SPI_t *spi, uint8_t bytes, uint8_t *outData) {
    for (uint8_t i = 0; i < bytes; i++) {
        SL2_SPI_Transmit_8bit(spi, outData[i]);
    }
}

void SL2_SPI_Read(SL2_SPI_t *spi, uint8_t bytes, uint8_t *inData) {
    for (uint8_t i = 0; i < bytes; i++) {
        inData[i] = SL2_SPI_Transmit_8bit(spi, 0x00);
    }
}




#endif // SL2_SPI_H