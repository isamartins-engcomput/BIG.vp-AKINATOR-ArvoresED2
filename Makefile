ifeq ($(OS),Windows_NT)
    PLATFORM_OS = WINDOWS
    export PATH := $(PATH);C:/raylib/mingw/bin
    EXT = .exe
    LDFLAGS = -L$(LIB_DIR)/src -lraylib -lopengl32 -lgdi32 -lwinmm
else
    PLATFORM_OS = LINUX
    EXT =
    LDFLAGS = -L$(LIB_DIR)/src -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
endif

LIB_DIR = raylib
LIB_PATH = $(LIB_DIR)/src/libraylib.a
INCLUDE_PATH = -I$(LIB_DIR)/src

SRC_DIR = morpheus/program/src
SRC = $(SRC_DIR)/main.c
TARGET = morpheusGame$(EXT)

CC = gcc
CFLAGS = -Wall -std=c99 -O2

all: $(LIB_PATH) $(TARGET) run

$(LIB_PATH):
	@echo "Detectado: $(PLATFORM_OS)"
	@if [ ! -d "$(LIB_DIR)" ]; then \
		git clone --depth 1 https://github.com/raysan5/raylib.git $(LIB_DIR); \
	fi
	cd $(LIB_DIR)/src && $(MAKE) PLATFORM=PLATFORM_DESKTOP

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) $(INCLUDE_PATH) $(LDFLAGS)
	@echo "Compilação concluída com sucesso!"

run: $(TARGET)
	@echo "Iniciando o MORPHEUS..."
	./$(TARGET)

clean:
	rm -f $(TARGET)

clean-all: clean
	rm -rf $(LIB_DIR)