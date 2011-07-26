CFLAGS  +=-I.
CCLINK  += -lfreeimage
PRGNAME  = exy

all: exy.c metadata.c metadata.h
	gcc -o $(PRGNAME) exy.c metadata.c $(CFLAGS) $(CCLINK)