CC = gcc

CFLAGS = -Wall -Wextra -Werror -std=c11

TARGET = lexer

SRC = main.c lexer.c utils.c keywords.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c lexer.h
	$(CC) $(CFLAGS) -c $< -o $@

run:
	./$(TARGET) sample.c

clean:
	rm -f *.o $(TARGET)

rebuild: clean all