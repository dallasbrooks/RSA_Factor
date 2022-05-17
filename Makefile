CC = gcc
CFLAGS = -Wall -g
LIBS = -lm

SOURCES := $(wildcard ./*.c)
HEADERS := $(wildcard ./*.h)

OUTPUT = RSA
PLAY = ./$(OUTPUT)

all: $(OUTPUT)

$(OUTPUT): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(OUTPUT) $(LIBS) 

run:
	$(PLAY)

clean:
	-$(RM) $(OUTPUT)