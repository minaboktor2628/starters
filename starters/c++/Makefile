# Mina Boktor

# Default c and cpp comilers
CPP = g++

# Include any libraries you would like to link here
# ex: -lpthread -lm
LIB = 

# Name of executable. Can override this when running make file. 
# ex: 'make TARGET=my_executable' 
TARGET ?= exec

# Where all your c or cpp files are
SRC = src

# Where to store all object file artifacts
# Remember to change .gitignore if you change this value
BUILD = build

# Where you are storing all your header files
INCLUDE = include

# Compiler flags. All warningings by default
FLAGS = -I$(INCLUDE) -Wall

# Collect c and cpp source files
CPP_FILES = $(wildcard $(SRC)/*.cpp)

# Object files for c and cpp
OBJ_FILES = $(patsubst $(SRC)/%.cpp, $(BUILD)/%.o, $(CPP_FILES))

# This tells make that these targets aren't real targets
.PHONY: all clean clean-obj

# Compile all source files
# Use this by running 'make all', or just 'make' for short 
all: $(TARGET)
	@echo "Build done"

# Link all object files to create final target
$(TARGET): $(OBJ_FILES)
	$(CPP) $(FLAGS) $^ -o $@ $(LIB)

# Rule for compiling cpp files
$(BUILD)/%.o: $(SRC)/%.cpp
	@mkdir -p $(BUILD)
	$(CPP) $(FLAGS) -c $< -o $@ 

debug: FLAGS += -g
debug: clean all

# Clean artifacts and executable
# Use this by running 'make clean'
clean:
	rm -rf $(BUILD) $(TARGET)
	@echo "Clean done"

# Clean only artifacts, but keep executable
# Use this by running 'make clean-obj'
clean-obj:
	rm -rf $(BUILD)
	@echo "Object files removed"
