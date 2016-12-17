
/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
#include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
#include <htc.h>        /* HiTech General Include File */
#endif

 
#include "state_manager.h"

int isInitialized = 0;
PedalState pedalState = {0, 0};

void initStateManager(void) {
    isInitialized = 0;
    getCurrentState();
}

PedalState getCurrentState(void) {
    if (!isInitialized) {
        uint8_t r;

        // read HEF Memory contents
        r = HEF_ByteArrayRead((void *) &pedalState, 1, sizeof (pedalState));

        if (pedalState.switch1 != 1) {
            pedalState.switch1 = 0; //fail safe
        }

        isInitialized = 1;
    }    
    return pedalState;
}


int getSwitch1State() {
    if (!isInitialized) {
        initStateManager();
    }
    return pedalState.switch1;
    
}

void updateSwitch1State(int state) {
    if (state != 1) {state = 0;}
    
    pedalState.switch1 = state;
    saveState();
}

void saveState(void) {
    uint8_t r;
    r = HEF_ByteArrayWrite(1, (void *) &pedalState, sizeof (pedalState));
}