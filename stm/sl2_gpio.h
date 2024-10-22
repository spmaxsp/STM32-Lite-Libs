
#ifndef SL2_GPIO_H
#define SL2_GPIO_H

#include "sl2_stm32g071_config.h"

#if defined(STM32G071xx)
    #include "stm32g0xx_ll_gpio.h"
    #include "stm32g0xx_ll_utils.h"
#else
    #error "Library not compatible with selected device (STM32G071xx) - at least for now ;) "
#endif


void SL2_GPIO_InitDigitalOutput(SL2_GPIO_t *gpio) {
    LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = gpio->pin;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;

    LL_GPIO_Init(gpio->port, &GPIO_InitStruct);
}


void SL2_GPIO_InitDigitalInput(SL2_GPIO_t *gpio) {
    LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = gpio->pin;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;

    LL_GPIO_Init(gpio->port, &GPIO_InitStruct);
}


void SL2_GPIO_InitDigitalInputPullup(SL2_GPIO_t *gpio) {
    LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = gpio->pin;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;

    LL_GPIO_Init(gpio->port, &GPIO_InitStruct);
}


uint8_t SL2_GPIO_DigitalRead(SL2_GPIO_t *gpio) {
    return LL_GPIO_IsInputPinSet(gpio->port, gpio->pin);
}


void SL2_GPIO_DigitalWrite(SL2_GPIO_t *gpio, uint8_t state) {
    if (state) {
        LL_GPIO_SetOutputPin(gpio->port, gpio->pin);
    } else {
        LL_GPIO_ResetOutputPin(gpio->port, gpio->pin);
    }
}

#endif // SL2_GPIO_H


