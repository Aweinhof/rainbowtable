# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -std=c++17

# Examples of specific includes
#SDL2_INCLUDE := -I /usr/local/Cellar/sdl2/2.28.2/include/SDL2
#SDL2_LIB := -L /usr/local/lib -lSDL2

# Libreries linker
SSL_LIB := -lssl -lcrypto

# Source files
SRC_DIR := src
SRCS := $(wildcard $(SRC_DIR)/*/*.cpp)
SRCS += $(wildcard $(SRC_DIR)/*.cpp)  # Add main.cpp to the source files

# Object files
OBJ_DIR := obj
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Executable name
EXEC := rainbowtable

# Make all
all: $(EXEC)

# Linking
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SDL2_LIB) $(SSL_LIB)

# Compilation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(SDL2_INCLUDE) -c -o $@ $<

# Clean
clean:
	rm -rf $(OBJ_DIR) $(EXEC)

# Run the game
run: $(EXEC)
	./$(EXEC)

.PHONY: all clean run
