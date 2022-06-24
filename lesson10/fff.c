#include "mbed.h"
#include "mbed.h"
#include <stdio.h>

AnalogIn photo0(A1);

PwmOut cw1(D3);
PwmOut ccw1(D5);
PwmOut cw(D7);
PwmOut ccw(D11);

int move_fadge(float *value){
    cw.period(0.02);
    ccw.period(0.02);
    cw1.period(0.02);
    ccw1.period(0.02);
    float i;
    i=0.01;

    if (*value>i){
        cw=0;
        ccw=0;
        cw1 = 0;
        ccw1 = 0.8;
        wait(0.2);
    }
    else {
        cw=0;
        ccw=0.8;
        cw1 = 0;
        ccw1 = 0;
        wait(0.2);
    }
    cw=0;
    ccw=0;
    cw1 = 0;
    ccw1 = 0;
    wait(0.2);
}

int main() {
    float k;
    while(1){   
    k=photo0.read();
        move_fadge(&(k));
    }
}