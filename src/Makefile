ifeq ($(OS), Windows_NT)
	OUT = cmt.exe
else
	OS := $(shell uname)
endif

ifeq ($(OS), Linux)
    LIBS = -lncurses
    OUT = cmt
endif

ifeq ($(OS), Darwin)
    LIBS = -lncurses
    OUT = cmt
endif




    
all: $(OUT)
	g++ main.cpp $(LIBS) -o $(OUT)
	
.PHONY: $(OUT)
