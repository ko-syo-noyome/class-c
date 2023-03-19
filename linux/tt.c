#include "mbed.h"
AnalogIn photo0(A0);
AnalogIn photo1(A1);
AnalogIn photo2(A2);

PwmOut cw1(D3);
PwmOut ccw1(D5);
PwmOut cw(D7);
PwmOut ccw(D11);

int main() {
    float i,j,k;
    float V=0.4;//白黒判別値
    while(1){
        i=photo0.read();//右センサー値
        j=photo1.read();//中センサー値
        k=photo2.read();//左センサー値
        if (j<V){ //中黒
            if (i<V && k<V){ //左&右センサー黒

                cw=0;
                ccw=0;
                cw1 = 0;
                ccw1 = 0.7;
                wait(0.1);

                cw=0;
                ccw=0.1;
                cw1 = 0;
                ccw1 = 0.4;
                wait(0.05);

            }else{
                cw=0;
                ccw=0.08;
                cw1 = 0;
                ccw1 = 0.4;
                wait(0.4);
            }

        }else {

            cw=0;
            ccw=0.4;
            cw1 = 0;
            ccw1 = 0.1;
            wait(0.1);      
        }
        cw=0;
        ccw=0;
        cw1 = 0;
        ccw1 = 0;
        wait(0.01);
    }
}
