## Compiler and flags
C_FLAGS       := -Wall -Wextra
DEBUG_FLAGS   := -g -DDEBUG
RELEASE_FLAGS := -O2 -DNDEBUG
PRE_FLAGS     :=
# PRE_FLAGS := -MMD -MP

# Project directory structure
BIN := bin
SRC := src
LIB := lib
INC := include
# MAINFILE := $(SRC)/main.cpp

# File extention
EXT := cpp

# Build directories and output
PROGRAM := <executable>
BUILD   := build

# Modes
MODE := debug
ifeq ($(MODE), debug)
    BUILD_DIR  := $(BUILD)/debug
    MODE_FLAGS := $(DEBUG_FLAGS)
    TARGET     := $(BIN)/debug/$(PROGRAM)
else ifeq ($(MODE), release)
    BUILD_DIR  := $(BUILD)/release
    MODE_FLAGS := $(RELEASE_FLAGS)
    TARGET     := $(BIN)/release/$(PROGRAM)
else ifeq ($(MODE), dist)
    BUILD_DIR  := $(BUILD)/dist
    MODE_FLAGS := $(RELEASE_FLAGS)
    TARGET     := $(BIN)/dist/$(PROGRAM)
endif

# Library search directories and flags
EXT_LIB :=
LDFLAGS :=
LDPATHS := $(addprefix -L,$(LIB) $(EXT_LIB))

# Include directories
INC_DIRS  := $(INC) $(shell find $(SRC) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# Construct build output and dependency filenames
SRCS := $(shell find $(SRC) -name *.$(EXT))
OBJS := $(subst $(SRC)/,$(BUILD_DIR)/,$(addsuffix .o,$(basename $(SRCS))))
DEPS := $(OBJS:.o=.d)

# Run task
run: $(TARGET)
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
	@echo "Building $(MODE) mode..."
	mkdir -p $(dir $@)
	$(CC) $(OBJS) -o $@ $(LDPATHS) $(LDFLAGS)

# Compile all cpp files
$(BUILD_DIR)/%.o: $(SRC)/%.$(EXT)
	mkdir -p $(dir $@)
	$(CC) $(C_FLAGS) $(MODE_FLAGS) $(PRE_FLAGS) $(INC_FLAGS) -c -o $@ $< $(LDPATHS) $(LDFLAGS)

# Clean task
.PHONY: clean
clean:
	@echo "Clearing $(MODE) mode..."
	$(RM) -r $(BUILD)/$(MODE) $(BIN)/$(MODE)

# Clean all modes
clean_all:
	@echo "Clearing all builds..."
	$(RM) -r $(BUILD) $(BIN)

# Include all dependencies
-include $(DEPS)



