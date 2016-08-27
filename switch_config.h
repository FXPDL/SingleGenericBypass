/* 
 * File:   switch_config.h
 * Author: Nancy
 *
 * Created on August 26, 2016, 10:42 PM
 */

#ifndef SWITCH_CONFIG_H
#define	SWITCH_CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* SWITCH_CONFIG_H */


#define Switch1_LED  LATCbits.LATC5
#define Switch1_Stomp PORTAbits.RA5
#define Switch1_Relay1 LATCbits.LATC0
#define Switch1_Relay10 LATCbits.LATC4


#define Switch2_LED  LATAbits.LATA2
#define Switch2_Stomp PORTAbits.RA4
#define Switch2_Relay1 LATCbits.LATC2
#define Switch2_Relay10 LATCbits.LATC1