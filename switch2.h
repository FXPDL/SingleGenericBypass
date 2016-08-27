/* 
 * File:   switch2.h
 * Author: Nancy
 *
 * Created on August 26, 2016, 10:34 PM
 */

#ifndef SWITCH2_H
#define	SWITCH2_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* SWITCH2_H */

#include <stdint.h>        /* For uint8_t definition */
#include "system.h"
#include "hardware_controls.h"
#include "switch_config.h"


void initSwitch2(void);
void updateSwitch2(void);
void setSwitch2State(int);

 