
#ifndef __STM32G071_CONFIG_H
#define __STM32G071_CONFIG_H

#if defined(STM32G071xx)
    #include "stm32g0xx_ll_gpio.h"
#else
    #error "Library not compatible with selected device (STM32G071xx) - at least for now ;) "
#endif


typedef struct {
    GPIO_TypeDef *port;
    uint32_t pin;
} SL2_GPIO_t;


typedef struct {
    GPIO_TypeDef *port;
    uint32_t pin;
    uint32_t af;
} SL2_SPI_PinMapping_t;


#if defined(STM32G071xx)

    // GPIO pin definitions
    #define SL2_GPIO_PA0  (SL2_GPIO_t){GPIOA, LL_GPIO_PIN_0}
    #define SL2_GPIO_PA1  (SL2_GPIO_t){GPIOA, LL_GPIO_PIN_1}
    #define SL2_GPIO_PA2  (SL2_GPIO_t){GPIOA, LL_GPIO_PIN_2}
    #define SL2_GPIO_PA3  (SL2_GPIO_t){GPIOA, LL_GPIO_PIN_3}
    #define SL2_GPIO_PA4  (SL2_GPIO_t){GPIOA, LL_GPIO_PIN_4}
    #define SL2_GPIO_PA5  (SL2_GPIO_t){GPIOA, LL_GPIO_PIN_5}
    #define SL2_GPIO_PA6  (SL2_GPIO_t){GPIOA, LL_GPIO_PIN_6}
    #define SL2_GPIO_PA7  (SL2_GPIO_t){GPIOA, LL_GPIO_PIN_7}
    #define SL2_GPIO_PA8  (SL2_GPIO_t){GPIOA, LL_GPIO_PIN_8}
    #define SL2_GPIO_PA9  (SL2_GPIO_t){GPIOA, LL_GPIO_PIN_9}
    #define SL2_GPIO_PA10 (SL2_GPIO_t){GPIOA, LL_GPIO_PIN_10}
    #define SL2_GPIO_PA11 (SL2_GPIO_t){GPIOA, LL_GPIO_PIN_11}
    #define SL2_GPIO_PA12 (SL2_GPIO_t){GPIOA, LL_GPIO_PIN_12}
    #define SL2_GPIO_PA13 (SL2_GPIO_t){GPIOA, LL_GPIO_PIN_13}
    #define SL2_GPIO_PA14 (SL2_GPIO_t){GPIOA, LL_GPIO_PIN_14}
    #define SL2_GPIO_PA15 (SL2_GPIO_t){GPIOA, LL_GPIO_PIN_15}

    #define SL2_GPIO_PB0  (SL2_GPIO_t){GPIOB, LL_GPIO_PIN_0}
    #define SL2_GPIO_PB1  (SL2_GPIO_t){GPIOB, LL_GPIO_PIN_1}
    #define SL2_GPIO_PB2  (SL2_GPIO_t){GPIOB, LL_GPIO_PIN_2}
    #define SL2_GPIO_PB3  (SL2_GPIO_t){GPIOB, LL_GPIO_PIN_3}
    #define SL2_GPIO_PB4  (SL2_GPIO_t){GPIOB, LL_GPIO_PIN_4}
    #define SL2_GPIO_PB5  (SL2_GPIO_t){GPIOB, LL_GPIO_PIN_5}
    #define SL2_GPIO_PB6  (SL2_GPIO_t){GPIOB, LL_GPIO_PIN_6}
    #define SL2_GPIO_PB7  (SL2_GPIO_t){GPIOB, LL_GPIO_PIN_7}
    #define SL2_GPIO_PB8  (SL2_GPIO_t){GPIOB, LL_GPIO_PIN_8}
    #define SL2_GPIO_PB9  (SL2_GPIO_t){GPIOB, LL_GPIO_PIN_9}
    #define SL2_GPIO_PB10 (SL2_GPIO_t){GPIOB, LL_GPIO_PIN_10}
    #define SL2_GPIO_PB11 (SL2_GPIO_t){GPIOB, LL_GPIO_PIN_11}
    #define SL2_GPIO_PB12 (SL2_GPIO_t){GPIOB, LL_GPIO_PIN_12}
    #define SL2_GPIO_PB13 (SL2_GPIO_t){GPIOB, LL_GPIO_PIN_13}
    #define SL2_GPIO_PB14 (SL2_GPIO_t){GPIOB, LL_GPIO_PIN_14}
    #define SL2_GPIO_PB15 (SL2_GPIO_t){GPIOB, LL_GPIO_PIN_15}

    #define SL2_GPIO_PC0  (SL2_GPIO_t){GPIOC, LL_GPIO_PIN_0}
    #define SL2_GPIO_PC1  (SL2_GPIO_t){GPIOC, LL_GPIO_PIN_1}
    #define SL2_GPIO_PC2  (SL2_GPIO_t){GPIOC, LL_GPIO_PIN_2}
    #define SL2_GPIO_PC3  (SL2_GPIO_t){GPIOC, LL_GPIO_PIN_3}
    #define SL2_GPIO_PC4  (SL2_GPIO_t){GPIOC, LL_GPIO_PIN_4}
    #define SL2_GPIO_PC5  (SL2_GPIO_t){GPIOC, LL_GPIO_PIN_5}
    #define SL2_GPIO_PC6  (SL2_GPIO_t){GPIOC, LL_GPIO_PIN_6}
    #define SL2_GPIO_PC7  (SL2_GPIO_t){GPIOC, LL_GPIO_PIN_7}
    #define SL2_GPIO_PC8  (SL2_GPIO_t){GPIOC, LL_GPIO_PIN_8}
    #define SL2_GPIO_PC9  (SL2_GPIO_t){GPIOC, LL_GPIO_PIN_9}
    #define SL2_GPIO_PC10 (SL2_GPIO_t){GPIOC, LL_GPIO_PIN_10}
    #define SL2_GPIO_PC11 (SL2_GPIO_t){GPIOC, LL_GPIO_PIN_11}
    #define SL2_GPIO_PC12 (SL2_GPIO_t){GPIOC, LL_GPIO_PIN_12}
    #define SL2_GPIO_PC13 (SL2_GPIO_t){GPIOC, LL_GPIO_PIN_13}
    #define SL2_GPIO_PC14 (SL2_GPIO_t){GPIOC, LL_GPIO_PIN_14}
    #define SL2_GPIO_PC15 (SL2_GPIO_t){GPIOC, LL_GPIO_PIN_15}

    #define SL2_GPIO_PD0  (SL2_GPIO_t){GPIOD, LL_GPIO_PIN_0}
    #define SL2_GPIO_PD1  (SL2_GPIO_t){GPIOD, LL_GPIO_PIN_1}
    #define SL2_GPIO_PD2  (SL2_GPIO_t){GPIOD, LL_GPIO_PIN_2}
    #define SL2_GPIO_PD3  (SL2_GPIO_t){GPIOD, LL_GPIO_PIN_3}
    #define SL2_GPIO_PD4  (SL2_GPIO_t){GPIOD, LL_GPIO_PIN_4}
    #define SL2_GPIO_PD5  (SL2_GPIO_t){GPIOD, LL_GPIO_PIN_5}
    #define SL2_GPIO_PD6  (SL2_GPIO_t){GPIOD, LL_GPIO_PIN_6}
    #define SL2_GPIO_PD7  (SL2_GPIO_t){GPIOD, LL_GPIO_PIN_7}
    #define SL2_GPIO_PD8  (SL2_GPIO_t){GPIOD, LL_GPIO_PIN_8}
    #define SL2_GPIO_PD9  (SL2_GPIO_t){GPIOD, LL_GPIO_PIN_9}

    #define SL2_GPIO_PF0  (SL2_GPIO_t){GPIOF, LL_GPIO_PIN_0}
    #define SL2_GPIO_PF1  (SL2_GPIO_t){GPIOF, LL_GPIO_PIN_1}
    #define SL2_GPIO_PF2  (SL2_GPIO_t){GPIOF, LL_GPIO_PIN_2}


    // SPI1 pin mappings for STM32G071  (from STM32G071 datasheet -> Table 13-17)
    #define SL2_SPI1_SCK_PA1       (SL2_SPI_PinMapping_t){GPIOA, LL_GPIO_PIN_1, LL_GPIO_AF_0}
    #define SL2_SPI1_SCK_PA5       (SL2_SPI_PinMapping_t){GPIOA, LL_GPIO_PIN_5, LL_GPIO_AF_0}
    #define SL2_SPI1_SCK_PB3       (SL2_SPI_PinMapping_t){GPIOB, LL_GPIO_PIN_3, LL_GPIO_AF_0}
    #define SL2_SPI1_SCK_PD8       (SL2_SPI_PinMapping_t){GPIOD, LL_GPIO_PIN_8, LL_GPIO_AF_1}

    #define SL2_SPI1_MISO_PA6      (SL2_SPI_PinMapping_t){GPIOA, LL_GPIO_PIN_6, LL_GPIO_AF_0}
    #define SL2_SPI1_MISO_PA11     (SL2_SPI_PinMapping_t){GPIOA, LL_GPIO_PIN_11, LL_GPIO_AF_0}
    #define SL2_SPI1_MISO_PB4      (SL2_SPI_PinMapping_t){GPIOB, LL_GPIO_PIN_4, LL_GPIO_AF_0}
    #define SL2_SPI1_MISO_PD5      (SL2_SPI_PinMapping_t){GPIOD, LL_GPIO_PIN_5, LL_GPIO_AF_1}

    #define SL2_SPI1_MOSI_PA2      (SL2_SPI_PinMapping_t){GPIOA, LL_GPIO_PIN_2, LL_GPIO_AF_0}
    #define SL2_SPI1_MOSI_PA7      (SL2_SPI_PinMapping_t){GPIOA, LL_GPIO_PIN_7, LL_GPIO_AF_0}   
    #define SL2_SPI1_MOSI_PA12     (SL2_SPI_PinMapping_t){GPIOA, LL_GPIO_PIN_12, LL_GPIO_AF_0} 
    #define SL2_SPI1_MOSI_PB5      (SL2_SPI_PinMapping_t){GPIOB, LL_GPIO_PIN_5, LL_GPIO_AF_0}
    #define SL2_SPI1_MOSI_PD6      (SL2_SPI_PinMapping_t){GPIOD, LL_GPIO_PIN_6, LL_GPIO_AF_1}
        
    #define SL2_SPI1_NSS_PA4       (SL2_SPI_PinMapping_t){GPIOA, LL_GPIO_PIN_4, LL_GPIO_AF_0}
    #define SL2_SPI1_NSS_PA15      (SL2_SPI_PinMapping_t){GPIOA, LL_GPIO_PIN_15, LL_GPIO_AF_0}
    #define SL2_SPI1_NSS_PB0       (SL2_SPI_PinMapping_t){GPIOB, LL_GPIO_PIN_0, LL_GPIO_AF_0}
    #define SL2_SPI1_NSS_PD9       (SL2_SPI_PinMapping_t){GPIOD, LL_GPIO_PIN_9, LL_GPIO_AF_1}

    // SPI2 pin mappings for STM32G071
    #define SL2_SPI2_SCK_PA0       (SL2_SPI_PinMapping_t){GPIOA, LL_GPIO_PIN_0, LL_GPIO_AF_0}
    #define SL2_SPI2_SCK_PB8       (SL2_SPI_PinMapping_t){GPIOB, LL_GPIO_PIN_8, LL_GPIO_AF_1}
    #define SL2_SPI2_SCK_PB10      (SL2_SPI_PinMapping_t){GPIOB, LL_GPIO_PIN_10, LL_GPIO_AF_5}
    #define SL2_SPI2_SCK_PB13      (SL2_SPI_PinMapping_t){GPIOB, LL_GPIO_PIN_13, LL_GPIO_AF_0}
    #define SL2_SPI2_SCK_PD1       (SL2_SPI_PinMapping_t){GPIOD, LL_GPIO_PIN_1, LL_GPIO_AF_1}

    #define SL2_SPI2_MISO_PA3      (SL2_SPI_PinMapping_t){GPIOA, LL_GPIO_PIN_3, LL_GPIO_AF_0}
    #define SL2_SPI2_MISO_PA9      (SL2_SPI_PinMapping_t){GPIOA, LL_GPIO_PIN_9, LL_GPIO_AF_4}
    #define SL2_SPI2_MISO_PB2      (SL2_SPI_PinMapping_t){GPIOB, LL_GPIO_PIN_2, LL_GPIO_AF_1}
    #define SL2_SPI2_MISO_PB6      (SL2_SPI_PinMapping_t){GPIOB, LL_GPIO_PIN_6, LL_GPIO_AF_4}
    #define SL2_SPI2_MISO_PB14     (SL2_SPI_PinMapping_t){GPIOB, LL_GPIO_PIN_14, LL_GPIO_AF_0}
    #define SL2_SPI2_MISO_PC2      (SL2_SPI_PinMapping_t){GPIOC, LL_GPIO_PIN_2, LL_GPIO_AF_1}
    #define SL2_SPI2_MISO_PD3      (SL2_SPI_PinMapping_t){GPIOD, LL_GPIO_PIN_3, LL_GPIO_AF_1}

    #define SL2_SPI2_MOSI_PA4      (SL2_SPI_PinMapping_t){GPIOA, LL_GPIO_PIN_4, LL_GPIO_AF_1}
    #define SL2_SPI2_MOSI_PA10     (SL2_SPI_PinMapping_t){GPIOA, LL_GPIO_PIN_10, LL_GPIO_AF_0}
    #define SL2_SPI2_MOSI_PB7      (SL2_SPI_PinMapping_t){GPIOB, LL_GPIO_PIN_7, LL_GPIO_AF_1}
    #define SL2_SPI2_MOSI_PB11     (SL2_SPI_PinMapping_t){GPIOB, LL_GPIO_PIN_11, LL_GPIO_AF_0}
    #define SL2_SPI2_MOSI_PB15     (SL2_SPI_PinMapping_t){GPIOB, LL_GPIO_PIN_15, LL_GPIO_AF_0}
    #define SL2_SPI2_MOSI_PC3      (SL2_SPI_PinMapping_t){GPIOC, LL_GPIO_PIN_3, LL_GPIO_AF_1}
    #define SL2_SPI2_MOSI_PD4      (SL2_SPI_PinMapping_t){GPIOD, LL_GPIO_PIN_4, LL_GPIO_AF_1}

    #define SL2_SPI2_NSS_PA8       (SL2_SPI_PinMapping_t){GPIOA, LL_GPIO_PIN_8, LL_GPIO_AF_1}
    #define SL2_SPI2_NSS_PB9       (SL2_SPI_PinMapping_t){GPIOB, LL_GPIO_PIN_9, LL_GPIO_AF_5}
    #define SL2_SPI2_NSS_PB12      (SL2_SPI_PinMapping_t){GPIOB, LL_GPIO_PIN_12, LL_GPIO_AF_0}
    #define SL2_SPI2_NSS_PD0       (SL2_SPI_PinMapping_t){GPIOD, LL_GPIO_PIN_0, LL_GPIO_AF_1}
    
#else
    #error "Library not compatible with selected device (STM32G071xx) - at least for now ;) "
#endif

#endif // __STM32G071_CONFIG_H





