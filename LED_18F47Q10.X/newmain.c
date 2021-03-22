/*
 * File:   newmain.c
 * Author: user
 *
 * Created on 19 de marzo de 2021, 05:19 PM
 */

#include "config.h"
#include <xc.h>
#define _XTAL_FREQ 4000000

void oscilador(void);

int main(void) {
    oscilador();
    TRISAbits.TRISA0 = 0;
    ANSELAbits.ANSELA0 = 0;
    while(1){
        PORTAbits.RA0 = 1;
        __delay_ms(1000);
        PORTAbits.RA0 = 0;
        __delay_ms(1000);
        
    }
    return 0;
}

void oscilador(){
    OSCCON1bits.NOSC = 0b111;//EXTOSC
    OSCCON1bits.NDIV = 0; //DIVISOR DE CLOCK A 1
}