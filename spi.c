/*
* =====================================================================================
*       Filename:  spi.c
*
*    Description:  File to control the SPI  
*
*        Version:  1.0 
*        Created:  27 November 2016 15:57
*
*         Author:  Olivier Pimi , pimium@gmail.com 
*   Organization:  Pimium 
*
* =====================================================================================
*/
 
 #include "spi.h"
#include "inc/LPC11xx.h"

 void init_SPI(void){
 //SET UP THE SPI
    LPC_IOCON->PIO0_9          = (LPC_IOCON->PIO0_9 & ~(0x3)) | 0x1;   //set up as MOSI function (sec. 7.4.34)
    LPC_IOCON->PIO0_8          = (LPC_IOCON->PIO0_8 & ~(0x3)) | 0x1;   //set up as MISO function
    LPC_IOCON->PIO0_2          = (LPC_IOCON->PIO0_2 & ~(0x3)) | 0x1;   //set up as SSEL function
    LPC_IOCON->SWCLK_PIO0_10   = (LPC_IOCON->SWCLK_PIO0_10 & ~(0x3)) | 0x2;   //set up as SCK function
    // LPC_IOCON->SCK_LOC  	   = (LPC_IOCON->SCK_LOC & ~(0x3));
    LPC_SYSCON->SYSAHBCLKCTRL  |= ((1<<11));                             //enable clock to SPI0 block (sec. 3.5.14)
    LPC_SYSCON->SSP0CLKDIV     |= 0xFF;                                //enable SPI clk by writing non-zero clk divisor (sec. 3.5.17)
    LPC_SYSCON->PRESETCTRL     |= 0x01;                                //clear SPI reset, SPI held in reset by default (sec. 3.5.2)
    LPC_SSP0->CR0              |= 0x07;                                //set for 8 bit transfer (sec. 14.6.1)
    LPC_SSP0->CR1              |= 0x02;                                //enable SPI (sec. 14.6.2)
    return;
}                                                                       