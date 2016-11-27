/*
* =====================================================================================
*       Filename:  sda_5708.h
*
*    Description:  Driver file for the sda 5708 device 
*
*        Version:  1.0 
*        Created:  26 November 2016 11:32
*
*         Author:  Olivier Pimi , pimium@gmail.com 
*   Organization:  Pimium 
*
* =====================================================================================
*/
#ifndef SDA_5708_H
#define SDA_5708_H

#include "hdr/hdr_gpio_masked_access.h"

#define CLK_pin 8
#define RESET_pin 9
#define CS_pin 8
#define DATA_pin 9

#define CLK (1 << CLK_pin)
#define RESET (1 << RESET_pin)
#define CS (1 << CS_pin)
#define DAT (1 << DATA_pin)

/// "variable" to manipulate the pin directly via GPIO masked access
#define SDA_clk	    							gpio_masked_access_t GPIO_MASKED_ACCESS(LPC_GPIO1, CLK_pin)
#define SDA_reset								gpio_masked_access_t GPIO_MASKED_ACCESS(LPC_GPIO1, RESET_pin)
#define SDA_cs  								gpio_masked_access_t GPIO_MASKED_ACCESS(LPC_GPIO0, CS_pin)
#define SDA_data								gpio_masked_access_t GPIO_MASKED_ACCESS(LPC_GPIO0, DATA_pin)

void init_SDA(void);
void set_SDA_clk(void);
void clear_SDA_clk(void);
void set_SDA_cs(void);
void clear_SDA_cs(void);
void set_SDA_reset(void);
void clear_SDA_reset(void);
void set_SDA_data(void);
void clear_SDA_data(void);
#endif /* SDA_5708_H */
