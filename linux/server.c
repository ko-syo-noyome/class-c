#include <SDL/SDL.h>
#include <SDL/SDL_net.h>

#define SERVER_HOST 5555

int main(int argc, char* argv[]){
	IPaddress server_ip;
	TCPsocket server_sock;

	SDL_Init(SDL_INIT_EVERYTHING);

	SDLNet_Init();

	SDLNet_ResolveHost(&server_ip, NULL, SERVER_HOST);

	server_sock = SDLNet_TCP_Open(&server_ip);

	if(server_sock != NULL){
		printf("OPEN\n");
	}
	else {
		printf("%s", SDLNet_GetError());
		return 1;
	}

	while(1){
		SDL_Delay(100);
	}

	return 0;
}