CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -std=c11
SRC = src/arvore.c src/livro.c src/main.c src/util.c src/biblioteca.c
OBJ = $(SRC:src/%.c=build/src/%.o)
TARGET = biblioteca

all: $(TARGET)

build/src/%.o: src/%.c
	mkdir -p build/src
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

clean:
	rm -rf build $(TARGET)
