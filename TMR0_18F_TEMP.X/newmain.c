/*
 * File:   newmain.c
 * Author: user
 *
 * Created on March 22, 2021, 3:54 PM
 */


#include "config.h"
#include <xc.h>
#include <pic18.h>
#define _XTAL_FREQ 4000000

void oscilador(void);
void config_tmr0_tempor(void);

int main(void) {
    oscilador();
    config_tmr0_tempor();
    while(1){
        
    }
    
    return 0;
}

void oscilador(void){
    OSCCON1bits.NOSC = 0b111;//EXTOSC
    OSCCON1bits.NDIV = 0; //DIVISOR DE CLOCK A 1
}

void config_tmr0_tempor(void){
    TRISAbits.TRISA0 = 0;
    ANSELAbits.ANSELA0 = 0;
    PORTAbits.RA0 = 0;
    
    //CONFIG INTERRUPCION
    INTCONbits.GIE = 1;//HABILITO LA INTERRUOCION GLOBAL
    PIR0bits.TMR0IF = 0;//BORRO LA BANDERA
    PIE0bits.TMR0IE = 1;//HABILITO EL TMR0
    
    //CONFIG TIMER_0
    T0CON0bits.T016BIT = 0;//8BITS
    T0CON1bits.T0CS = 0b010;//TRABAJO CON EL RELOJ INTERNO
    T0CON1bits.T0ASYNC = 1;//NO SINCRONIZADO
    T0CON1bits.T0CKPS = 0b1001;//PREESCALER 512
    T0CON0bits.T0EN = 1;//HABILITO EL TMR0
    
    TMR0=61;
}

 void __interrupt() TMR_0(void){
     if(PIR0bits.TMR0IF == 1){
         PIR0bits.TMR0IF = 0;
         LATAbits.LATA0 = !LATAbits.LATA0;
     }
     TMR0=61;//CARGO NUEVAMENTE EL VALOR
}