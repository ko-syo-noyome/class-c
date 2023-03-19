#include <SDL2/SDL_net.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define warning(FUNC)	printf("SDLNet_"#FUNC": %s\n", SDLNet_GetError())
#define error(FUNC)	{ warning(FUNC);  exit(1); }


void server(int port)
{
    IPaddress ip;
    if (SDLNet_ResolveHost(&ip, 0, port) == -1)		error(ResolveHost);

    TCPsocket server;
    if (!(server = SDLNet_TCP_Open(&ip)))		error(TCP_Open);

    SDLNet_SocketSet servers;
    if (!(servers = SDLNet_AllocSocketSet(2)))		error(AllocSocketSet);
    if (SDLNet_TCP_AddSocket(servers, server) < 0)	error(AddSocket);

    printf("listening for connections on port %i\n", port);

    for (;;) {
        SDLNet_CheckSockets(servers, ~0); // wait for connection request
        if (SDLNet_SocketReady(server)) { // connection request received
            TCPsocket client;
            if (!(client = SDLNet_TCP_Accept(server))) { // accept connection
            warning(TCP_Accept);
            continue;
            }

            IPaddress *remoteip;
            if (!(remoteip = SDLNet_TCP_GetPeerAddress(client)))	warning(TCP_GetPeerAddress);
            unsigned char *h = (void *)&remoteip->host, *p = (void *)&remoteip->port;
            printf("connection accepted from %i.%i.%i.%i:%hu\n",
            h[0], h[1], h[2], h[3], p[0] * 256 + p[1]);
//-------------------------------------------------------

            for(;;){
                char outdata[1024];
                int outlen=SDLNet_TCP_Recv(client,outdata,sizeof(outdata));
                if (outlen==0) break;
                else printf("received: %.*s", outlen,outdata);
            }
            char indata[1024];
            printf("client connection closed\n");
            if (*indata=='Q') break;
            
        }
    }
    printf("server connection closed\n");
    SDLNet_TCP_Close(server);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("usage: %s port\n", argv[0]);
        exit(1);
    }
    if (SDLNet_Init() == -1) error(Init);
    server(atoi(argv[1]));
    SDLNet_Quit();

    return 0;
}
