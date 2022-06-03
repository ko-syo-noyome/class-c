#include "window.h"
#define SIZE 4

int main(int argc, char **argv){
    size(400, 300);
    title("ball");
    int x = 0;
    int y = height / 2;

    int dx = 3;

    for (;;) {

        clear();
        fillRectangle(x - SIZE, y - SIZE, x + SIZE, y + SIZE);
     
        delay(10);
   
        x += dx;

        if (x >= width || x <= 0) dx = -dx;
    }
    return 0;
}