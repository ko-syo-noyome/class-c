#include <stdio.h>
#include <SDL_net.h>
#include <string.h>


#define warning(FUNC)	printf("SDLNet_"#FUNC": %s\n", SDLNet_GetError())
#define error(FUNC)	{ warning(FUNC);  exit(1); }

// int main(int argc, char **argv)
// {
//     if (argc != 2) {
// 	printf("usage: %s port\n", argv[0]);
// 	exit(1);
//     }

//     if (SDLNet_Init() == -1) error(Init);

//     server(atoi(argv[1]));

//     SDLNet_Quit();

//     return 0;
// }

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

	
	IPaddress ip;
	if (SDLNet_ResolveHost(&ip, "localhost", 9999) == -1)
		error(ResolveHost);

	
	//printf("address is %s\n",ip2str(&ip));
	
	TCPsocket socket=SDLNet_TCP_Open(&ip);
    if (0==socket) error(TCP_Open);


    for (;;){
        char buffer[1024];
        
        printf("enter message:");
        fgets(buffer, sizeof(buffer), stdin);
        
        int len=sizeof(buffer);
        if ((SDLNet_TCP_Send(socket, buffer, len)) < len) error(TCP_Send);

        
        if (*buffer=='q' || *buffer=='Q') break;
        
    }


	SDLNet_TCP_Close(socket);

    SDLNet_Quit();

    return 0;
}


