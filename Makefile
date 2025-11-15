ifeq ($(OS), Windows_NT)
	OUT = chronometer.exe
else
	OS := $(shell uname)
endif

ifeq ($(OS), Linux)
    LIBS = -lncurses
    OUT = chronometer
endif

ifeq ($(OS), Darwin)
    LIBS = -lncurses
    OUT = chronometer
endif




    
all: $(OUT)
	g++ main.cpp $(LIBS) -o $(OUT)
	
.PHONY: $(OUT)
