CC=gcc
LIBS=-lm
DEBUG=-g

main: main.c
	gcc main.c -o $@ $(LIBS)

opt0: main.c
	gcc main.c -o $@ $(LIBS) -O0

opt1: main.c
	gcc main.c -o $@ $(LIBS) -O1

opt2: main.c
	gcc main.c -o $@ $(LIBS) -O2

opt3: main.c
	gcc main.c -o $@ $(LIBS) -O3

debug: main.c
	gcc $(DEBUG) main.c -o $@ $(LIBS)

.PHONY: clean
clean:
	rm main

