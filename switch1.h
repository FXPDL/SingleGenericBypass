/* 
 * File:   switch1.h
 * Author: Nancy
 *
 * Created on August 26, 2016, 10:24 PM
 */

#ifndef SWITCH1_H
#define	SWITCH1_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* SWITCH1_H */

#include <stdint.h>        /* For uint8_t definition */
#include "system.h"
#include "hardware_controls.h"
#include "switch_config.h"

void initSwitch1(void);
void updateSwitch1(void);
void setSwitch1State(int);
