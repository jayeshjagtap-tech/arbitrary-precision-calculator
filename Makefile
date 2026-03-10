CC = gcc
CFLAGS = -std=c99 -Wall -Wextra

SRC = main.c utils.c addition.c subtraction.c multiplication.c division.c modulus.c

OBJ = $(SRC:.c=.o)
TARGET = APC.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.c apc.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
