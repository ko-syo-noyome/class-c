CFLAGS  = -I/opt/local/include/SDL2 -I/usr/local/include/SDL2 -I/usr/include/SDL2 -Wall -g
LDFLAGS = -L/opt/local/lib
LDLIBS  = -lSDL2_net

SRCS    = $(wildcard 13-*.c)
PROGS   = $(SRCS:.c=)

all : $(PROGS)

clean : .FORCE
	rm -f $(PROGS) *~

.FORCE :
