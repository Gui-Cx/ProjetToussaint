SRC_DIR := ./src
HEAD_DIR := ./include
OBJ_DIR := ./obj
LIB_DIR := ./lib
TEST_DIR := ./test
SRC_FILES := $(filter-out $(SRC_DIR)/main.cpp, $(shell find $(SRC_DIR) -name "*.cpp"))
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
GLAD_FILES := ./lib/glad/src/glad.c
LFLAGS := -lglfw3 -ldl -lGL -lGLU -lGLEW -lX11 -lpthread
#SLFLAGS = $(LIB_DIR)/stb_image.a
INCFLAGS = -I./include -I./include/core -I./src -I./lib/glad/include/ -I./lib/glm/

main: $(SRC_DIR)/main.cpp $(OBJ_FILES) 
	g++-10 -g $(INCFLAGS) $< -o $@ $(OBJ_FILES) $(GLAD_FILES) $(LFLAGS) $(SLFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEAD_DIR)/%.h
	@mkdir -p $(@D)
	g++-10 -g $(INCFLAGS) -c -o $@ $<

.PHONY : all
all: main

clean :
	rm main