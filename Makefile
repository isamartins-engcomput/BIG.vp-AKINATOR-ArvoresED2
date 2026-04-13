ifeq ($(OS),Windows_NT)
    PLATFORM_OS = WINDOWS
    export PATH := $(PATH);C:/raylib/mingw/bin
    EXT = .exe
    LDFLAGS = -L$(LIB_DIR)/src -lraylib -lopengl32 -lgdi32 -lwinmm
else
    PLATFORM_OS = LINUX
    EXT =
    LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
endif

LIB_DIR = raylib
LIB_PATH = $(LIB_DIR)/src/libraylib.a
INCLUDE_PATH = -I$(LIB_DIR)/src
LIB_SEARCH = -L$(LIB_DIR)/src

SRC_DIR = morpheus/program/src
SRC = $(SRC_DIR)/main.c
TARGET = morpheusGame$(EXT)

CC = gcc
CFLAGS = -Wall -std=c99 -O2

all: $(LIB_PATH) $(TARGET) run

deps:
ifeq ($(PLATFORM_OS),LINUX)
	@echo "Instalando dependências do sistema X11 e Áudio (pode pedir sua senha)..."
	sudo apt-get update
	sudo apt-get install -y libx11-dev libxcursor-dev libxinerama-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libasound2-dev
endif

$(LIB_PATH): deps
	@echo "Detectado: $(PLATFORM_OS)"
	@if [ ! -d "$(LIB_DIR)" ]; then \
		git clone --depth 1 https://github.com/raysan5/raylib.git $(LIB_DIR); \
	fi
	$(MAKE) -C $(LIB_DIR)/src PLATFORM=PLATFORM_DESKTOP

$(TARGET): $(SRC)
	$(CC) $(SRC) $(CFLAGS) $(INCLUDE_PATH) $(LIB_SEARCH) -o $(TARGET) $(LDFLAGS)
	@echo "Compilação concluída com sucesso!"

run: $(TARGET)
	@echo "Iniciando o MORPHEUS..."
	./$(TARGET)

clean:
	rm -f $(TARGET)

clean-all: clean
	rm -rf $(LIB_DIR)
