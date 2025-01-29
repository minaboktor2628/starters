## Compiler and flags
CXX_FLAGS := -Wall -Wextra -std=c++17
DEBUG_FLAGS := -ggdb -O0
RELEASE_FLAGS := -O2 -DNDEBUG
PRE_FLAGS :=
# PRE_FLAGS := -MMD -MP

# Project directory structure
BIN := bin
SRC := src
LIB := lib
INC := include
# MAINFILE := $(SRC)/main.cpp

# Build directories and output
TARGET := $(BIN)/main
BUILD := build

# Modes
MODE := debug
ifeq ($(MODE), debug)
    BUILD_DIR := $(BUILD)/debug
    MODE_FLAGS := $(DEBUG_FLAGS)
    TARGET := $(BIN)/debug/main
else ifeq ($(MODE), release)
    BUILD_DIR := $(BUILD)/release
    MODE_FLAGS := $(RELEASE_FLAGS)
    TARGET := $(BIN)/release/main
else ifeq ($(MODE), dist)
    BUILD_DIR := $(BUILD)/dist
    MODE_FLAGS := $(RELEASE_FLAGS)
    TARGET := $(BIN)/dist/main
endif

# Library search directories and flags
EXT_LIB :=
LDFLAGS :=
LDPATHS := $(addprefix -L,$(LIB) $(EXT_LIB))

# Include directories
INC_DIRS := $(INC) $(shell find $(SRC) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# Construct build output and dependency filenames
SRCS := $(shell find $(SRC) -name *.cpp)
OBJS := $(subst $(SRC)/,$(BUILD_DIR)/,$(addsuffix .o,$(basename $(SRCS))))
DEPS := $(OBJS:.o=.d)

# Run task
run: $(TARGET)
	@echo "🚀 Executing in $(MODE) mode..."
	./$(TARGET) $(ARGS)

# Build tasks
build: $(TARGET)

debug:
	@$(MAKE) build MODE=debug

release:
	@$(MAKE) build MODE=release

dist:
	@$(MAKE) build MODE=dist

# Main task
$(TARGET): $(OBJS)
	@echo "🚧 Building $(MODE) mode..."
	mkdir -p $(dir $@)
	$(CXX) $(OBJS) -o $@ $(LDPATHS) $(LDFLAGS)

# Compile all cpp files
$(BUILD_DIR)/%.o: $(SRC)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXX_FLAGS) $(MODE_FLAGS) $(PRE_FLAGS) $(INC_FLAGS) -c -o $@ $< $(LDPATHS) $(LDFLAGS)

# Clean task
.PHONY: clean
clean:
	@echo "🧹 Clearing $(MODE) mode..."
	rm -rf $(BUILD)/$(MODE) $(BIN)/$(MODE)

# Clean all modes
clean_all:
	@echo "🧹 Clearing all builds..."
	rm -rf $(BUILD) $(BIN)

# Include all dependencies
-include $(DEPS)
