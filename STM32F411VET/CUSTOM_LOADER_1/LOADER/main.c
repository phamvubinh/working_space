#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"

/* All LED are on PORT D */
#define LED_PORT GPIOD

/* Define LED pin */
#define LED0_PIN (1<<12)
#define LED1_PIN (1<<13)
#define LED2_PIN (1<<14)
#define LED3_PIN (1<<15)

/* Define application address */
#define APPLICATION_ADDRESS 		0x08008000

/* Define function pointer to point to Reset_Handler */
typedef  void (*pFunction)(void);
pFunction Jump_To_Application;

/* Define variable to save address of Reset_Handler */
uint32_t JumpAddress;

/* Init GPIO to coltrol all 4 LEDs */
void LED_Init(void);

int main(void)
{
    int blink_time = 0;
    /* Init to use HAL Library */
    HAL_Init();

    /* Init LED */
    LED_Init();

    while(1)
    {
        for(blink_time = 0; blink_time < 6; blink_time ++)
        {
            /* Toggle LED1_PIN */
            HAL_GPIO_TogglePin(LED_PORT, LED1_PIN);
            /* Delay 1000 ms */
            HAL_Delay(1000);
        }
       
        /* An application is flashed already in APPLICATION_ADDRESS by using Keil and IROM config */
		/* Check value at APPLICATION_ADDRESS: it is __init_sp() so its value should be in SRAM range */ 
		if (((*(__IO uint32_t*)APPLICATION_ADDRESS) & 0x2FFE0000 ) == 0x20000000)
		{ 
			/* Jump to user application */
			/* The next address in vector table is the Reset_Handler function defined in vector table of application */
			JumpAddress = *(__IO uint32_t*) (APPLICATION_ADDRESS + 4);
			Jump_To_Application = (pFunction) JumpAddress;
			/* Initialize user application's Stack Pointer */
			__set_MSP(*(__IO uint32_t*) APPLICATION_ADDRESS);
			/* Run the Reset_Handler and function of application */
			Jump_To_Application();
		}	
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
    GPIO_InitStruct.Pull    = GPIO_NOPULL;
    GPIO_InitStruct.Speed   = GPIO_SPEED_LOW;

    /* Init the LED pin function */
    HAL_GPIO_Init(LED_PORT, &GPIO_InitStruct);
    HAL_GPIO_WritePin(LED_PORT, LED2_PIN, GPIO_PIN_RESET);
}