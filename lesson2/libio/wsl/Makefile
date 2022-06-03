PROGRAM = test

# The executable file depends on SDL2.dll, SDL2_ttf.dll, libfreetype-6.dll, and
# zlib1.dll.  These files must be present in the same directory as the
# executable or it will refuse to run.  (They can be installed in a system
# directory, but you want to avoid that if at all possible.)

CC      = /usr/bin/x86_64-w64-mingw32-gcc
CFLAGS  = -Iinclude -Wall -g
LDFLAGS = -L/usr/x86_64-w64-mingw32/lib -Llib
LDLIBS  = -lmingw32 -lSDL2main -lSDL2_ttf -lSDL2 -lm

$(PROGRAM).exe : $(PROGRAM).o window.o
	$(CC) $(LDFLAGS) -o $@ $+ $(LDLIBS)

$(PROGRAM).o : $(PROGRAM).c window.h
window.o : window.c window.h

run : $(PROGRAM).exe
	./$(PROGRAM).exe

clean : .FORCE
	rm -f $(PROGRAM).exe $(PROGRAM).o window.o *~

.FORCE :
