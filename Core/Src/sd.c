/*
 * sd.c
 *
 *  Created on: Dec 14, 2020
 *      Author: BPolko
 */
#include <stdbool.h>
#include "main.h"
#include "fatfs.h"

void ConDetect(bool type)
{
	FATFS fs;
	FRESULT fresult;
	fresult = f_mount(&fs, "1", 1);
	if(type == 1)
	{
		send_uart("Wybrano SPI\n");
		bool stan = HAL_GPIO_ReadPin(SPI1_CD_GPIO_Port, SPI1_CD_Pin);
		if(stan == 1 )
		{
			send_uart(" Karta podlaczona do SPI\n");
			HAL_GPIO_WritePin(SPI1_LED_GPIO_Port, SPI1_LED_Pin, GPIO_PIN_SET);
		}
		else
		{
			send_uart("Brak polaczenia katy po SPI\n");
			HAL_GPIO_WritePin(SPI1_LED_GPIO_Port, SPI1_LED_Pin, GPIO_PIN_RESET);
		}
	}
	else if(type == 0)
	{
		send_uart(" Wybrano SDI\n");
		bool stan = HAL_GPIO_ReadPin(SDIO_CD_GPIO_Port, SDIO_CD_Pin);
		if(stan == 1 )
		{
			send_uart(" Karta podlaczona do SDIO\n");
			HAL_GPIO_WritePin(SDIO_LED_GPIO_Port, SDIO_LED_Pin, GPIO_PIN_SET);
		}
		else
		{
			send_uart("Brak polaczenia katy po SDIO\n");
			HAL_GPIO_WritePin(SDIO_LED_GPIO_Port, SDIO_LED_Pin, GPIO_PIN_RESET);
		}
	}
	else
	{
		send_uart(" blad\n");
	}

}
void MemCheck()
{

}
