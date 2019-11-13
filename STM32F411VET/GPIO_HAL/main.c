#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"

/* All LED are on PORT D */
#define LED_PORT GPIOD

/* Define LED pin */
#define LED0_PIN (1<<12)
#define LED1_PIN (1<<13)
#define LED2_PIN (1<<14)
#define LED3_PIN (1<<15)

/* Init GPIO to coltrol all 4 LEDs */
void LED_Init(void);

int main(void)
{
    /* Init to use HAL Library */
    HAL_Init();

    /* Init LED */
    LED_Init();

    while(1)
    {
        /* Toggle LED1_PIN */
        HAL_GPIO_TogglePin(LED_PORT, LED1_PIN);
        
        /* Delay 1000 ms */
        HAL_Delay(1000);
    }
    return 0;
}

void LED_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStruct;

    /* Enable clock for port D */
    __HAL_RCC_GPIOD_CLK_ENABLE();
    
    /* Configure the GPIO_LED pin as output mode, pullup option and speed fast */
    GPIO_InitStruct.Pin     = LED0_PIN | LED1_PIN | LED2_PIN | LED3_PIN;
    GPIO_InitStruct.Mode    = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull    = GPIO_PULLUP;
    GPIO_InitStruct.Speed   = GPIO_SPEED_FAST;
    
    /* Init the LED pin function */
    HAL_GPIO_Init(LED_PORT, &GPIO_InitStruct);
}