#include <stdio.h>

#include "SDL_net.h"

int main(int argc, char **argv)
{
    SDLNet_Init();
    doAllYourNetworkStuffHere();
    SDLNet_Quit(); 
    return 0;
}
