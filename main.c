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
#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */         
          
#include "switch1.h"          /* Switch control */

/******************************************************************************/
/* Main Program                                                               */

/******************************************************************************/
void main(void) {
    ConfigureOscillator();
    InitApp();
        
    initSwitch1();
    
    while (1) {
        updateSwitch1();

    }

}