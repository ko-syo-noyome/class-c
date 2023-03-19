#include <stdio.h>
#include <SDL_net.h>
#include <string.h>


#define warning(FUNC)	printf("SDLNet_"#FUNC": %s\n", SDLNet_GetError())
#define error(FUNC)	{ warning(FUNC);  exit(1); }
#define MAX_PACKET_SIZE 1024

char *ip2str(IPaddress *ipp){
	static char buffer[64];
	unsigned char *h=(void  *)&ipp->host;
	unsigned char *p=(void *)&ipp->port;

	snprintf(buffer,sizeof(buffer),"%i.%i.%i.%i:%i\n",h[0],h[1],h[2],h[3],p[0]*256+p[1]);

	return buffer;
}

int main(int argc, char **argv)
{
    SDLNet_Init();

	UDPsocket socket=SDLNet_UDP_Open(0);
    if (0==socket) error(UDP_Open);

    UDPpacket *packet=SDLNet_AllocPacket(MAX_PACKET_SIZE);
    if(!packet) error(AllocPacket);

    char message[]="Hello server san!!";
    strcpy((void *)packet->data,message);
    packet->len=sizeof(message);

    int n=SDLNet_UDP_Send(socket,-1,packet);
    if (0==n) warning(UDP_Send);

    // if(SDLNet_ResolveHost(&packet->address,"localhost",6666)<0)
    //     error(ResolveHost);

	SDLNet_UDP_Close(socket);

    SDLNet_Quit();

    return 0;
}


