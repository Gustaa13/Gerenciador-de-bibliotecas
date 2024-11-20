# Nome do executável
TARGET = biblioteca

# Diretórios
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Arquivos de origem e cabeçalho
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)
HEADERS = $(wildcard $(INCLUDE_DIR)/*.h)

# Compilador e flags
CC = gcc
CFLAGS = -I$(INCLUDE_DIR) -Wall -Wextra -std=c11
LDFLAGS =

# Regra padrão
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# Regra para compilar arquivos .c em .o
$(BUILD_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)  # Cria os diretórios necessários
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Regra padrão de limpeza e recompilação
rebuild: clean all

# Declaração de phony targets
.PHONY: all clean rebuild
