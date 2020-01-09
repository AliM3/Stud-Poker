#Author : Ali Mohammad
#File: Makefile

CC = gcc

#cardMain.c, cardFunctions.c, 
#and cardHeader.h must be in 
#the same directory. 
FILES = cardMain.c cardFunctions.c cardTester.c

OUT_EXE = card.out

build: $(FILES)
	$(CC) $(FILES) -o $(OUT_EXE)