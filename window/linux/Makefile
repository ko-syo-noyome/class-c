PROGRAM = test

CFLAGS  = -Wall -g
LDLIBS  = -lSDL2_ttf -lSDL2 -lm

$(PROGRAM) : $(PROGRAM).o window.o

$(PROGRAM).o : $(PROGRAM).c window.h
window.o : window.c window.h

run : $(PROGRAM)
	./$(PROGRAM)

clean : .FORCE
	rm -f $(PROGRAM) $(PROGRAM).o window.o *~

.FORCE :
