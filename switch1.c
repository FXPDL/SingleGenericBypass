/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
#include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
#include <htc.h>        /* HiTech General Include File */
#endif


#include "state_manager.h"
#include "switch1.h"


int switch1_state = -1; //initialize to an invalid value so the initialize will run.

int switch1_pressed = 0;  
int switch1_up = 1;  
int switch1_toggle = 0;

void initSwitch1() {
    int initState = getSwitch1State();
    setSwitch1State(initState);
}

void updateSwitch1(void) {

    //http://www.kennethkuhn.com/electronics/debounce.c
    /* Step 1: Update the integrator based on the input signal.  Note that the 
    integrator follows the input, decreasing or increasing towards the limits as 
    determined by the input state (0 or 1). */

    if (Switch1_Stomp == 0) {
        if (switch1_pressed > 0) {
            switch1_pressed--;
        }
    } else if (switch1_pressed < debounce_limit) {
        switch1_pressed++;
    }

    /* Step 2: Update the output state based on the integrator.  Note that the
    output will only change states if the integrator has reached a limit, either
    0 or MAXIMUM. */

    if (switch1_pressed == 0) {
        if (switch1_state == 1) {
            if (switch1_up == 1) {
                switch1_toggle = 1;
            }
        } else {
            //switch1 was off, so turn it on
            switch1_toggle = 0;
            setSwitch1State(1);
        }

        
        switch1_up = 0;
    } else if (switch1_pressed >= debounce_limit) {
        if (switch1_toggle == 1) {
            setSwitch1State(0);
        }
        switch1_toggle = 0;
        switch1_up = 1;
        switch1_pressed = debounce_limit; /* defensive code if integrator got corrupted */
    }    
    
    
}


void setSwitch1State(int f_state) {
    if (switch1_state == f_state) {return;}
    switch1_state = f_state;
    Switch1_LED = f_state;
    Switch1_Relay1 = f_state;
    Switch1_Relay10 = !f_state;

    wait_ms(relay_delay);

    Switch1_Relay1 = 0;
    Switch1_Relay10 = 0;

    updateSwitch1State(switch1_state);  
    wait_ms(relay_delay);
}
