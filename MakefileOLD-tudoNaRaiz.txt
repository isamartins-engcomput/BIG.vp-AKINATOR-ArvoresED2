# 1. Detecção do Sistema Operacional
ifeq ($(OS),Windows_NT)
    PLATFORM_OS = WINDOWS
    export PATH := $(PATH);C:/raylib/mingw/bin
    EXT = .exe
    # Flags específicas para Windows (MinGW)
    LDFLAGS = -L$(LIB_DIR)/src -lraylib -lopengl32 -lgdi32 -lwinmm
else
    PLATFORM_OS = LINUX
    EXT =
    # Flags específicas para Linux
    LDFLAGS = -L$(LIB_DIR)/src -lraylib -lm -lpthread -ldl -lrt -lX11
endif

# 2. Configurações de Pastas
LIB_DIR = raylib
LIB_PATH = $(LIB_DIR)/src/libraylib.a
INCLUDE_PATH = -I$(LIB_DIR)/src

# 3. Configurações do Compilador
CC = gcc
CFLAGS = -Wall -std=c99 -O2
TARGET = meu_jogo$(EXT)
SRC = main.c

# Regra principal
all: $(LIB_PATH) $(TARGET)

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

clean:
	rm -f $(TARGET)

clean-all: clean
	rm -rf $(LIB_DIR)
