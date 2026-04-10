# 1. Detecção do Sistema Operacional
ifeq ($(OS),Windows_NT)
    PLATFORM_OS = WINDOWS
    export PATH := $(PATH);C:/raylib/mingw/bin
    EXT = .exe
    # Flags para Windows
    LDFLAGS = -L$(LIB_DIR)/src -lraylib -lopengl32 -lgdi32 -lwinmm
else
    PLATFORM_OS = LINUX
    EXT =
    # Flags exatas que você pediu para compilar no Linux com a lib local
    LDFLAGS = -L$(LIB_DIR)/src -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
endif

# 2. Configurações de Pastas
LIB_DIR = raylib
LIB_PATH = $(LIB_DIR)/src/libraylib.a
INCLUDE_PATH = -I$(LIB_DIR)/src

# Nova estrutura de diretórios do projeto
SRC_DIR = morpheus/program/src
SRC = $(SRC_DIR)/main.c
TARGET = morpheusGame$(EXT)

# 3. Configurações do Compilador
CC = gcc
CFLAGS = -Wall -std=c99 -O2

# Regra principal: Baixa a raylib, compila o código e RODA o jogo
all: $(LIB_PATH) $(TARGET) run

# 4. Baixa e compila a Raylib automaticamente
$(LIB_PATH):
	@echo "Detectado: $(PLATFORM_OS)"
	@if [ ! -d "$(LIB_DIR)" ]; then \
		git clone --depth 1 https://github.com/raysan5/raylib.git $(LIB_DIR); \
	fi
	cd $(LIB_DIR)/src && $(MAKE) PLATFORM=PLATFORM_DESKTOP

# 5. Compila o seu código
$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) $(INCLUDE_PATH) $(LDFLAGS)
	@echo "Compilação concluída com sucesso!"

# 6. Executa o jogo automaticamente
run: $(TARGET)
	@echo "Iniciando o MORPHEUS..."
	./$(TARGET)

clean:
	rm -f $(TARGET)

clean-all: clean
	rm -rf $(LIB_DIR)