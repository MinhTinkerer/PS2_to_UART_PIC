/******************************************************************************/
/* Change log                                                                 *
 *
 *
 *
 * Date         Revision    Comments
 * MM/DD/YY
 * --------     ---------   ----------------------------------------------------
 * 01/21/15     1.2         Added log.
/******************************************************************************/

/******************************************************************************/
/* Contains Timer functions.
 *
/******************************************************************************/

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/
#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "Timer.h"

/******************************************************************************/
/* Functions
 *
/******************************************************************************/

/******************************************************************************/
/* Timer2Init
 *
 * The function initializes timer 2. The interrupt is enabled.
/******************************************************************************/
void Timer2Init(unsigned char time)
{
    unsigned char postscaler =0xF;// postsclaer divide by 16
    unsigned char prescaler =3;// divid by 64
    CCP2CONbits.CCP2M = 0b1010;//generate software interrupt only 
    PR2 = time;        
    T2CON |= postscaler << 3;
    T2CON |= prescaler;
    
    T2CONbits.TMR2ON = 1;//timer2 on
    PIE1bits.TMR2IE = 1;//enable timer 2 interupt
}