# Version number
VERSION := 1.0.0

## Compiler and flags
CC              := gcc
C_FLAGS         := -Wall -Wextra
DEBUG_FLAGS     := -g -DDEBUG
RELEASE_FLAGS   := -DNDEBUG
DIST_FLAGS      := -O3 -DNDEBUG
PRE_FLAGS       := -MMD -MP

# File extention
EXT :=

# Project directory structure
BIN := bin
SRC := src
LIB := lib
INC := include
MAINFILE := $(SRC)/main.$(EXT)

# Formatter and Linter
CLANG_FORMAT := clang-format
CLANG_TIDY   := clang-tidy

# Find all C++ source and header files
FORMAT_FILES := $(shell find $(SRC) $(INC) -type f \( -name "*.cpp" -o -name "*.hpp" -o -name "*.h" -o -name "*.c" \))
LINT_FILES   := $(FORMAT_FILES)

# Build directories and output
PROGRAM := <executable>
BUILD   := build

# Modes
MODE := release
ifeq ($(MODE), debug)
    BUILD_DIR  := $(BUILD)/$(MODE)
    MODE_FLAGS := $(DEBUG_FLAGS)
    TARGET     := $(BIN)/$(MODE)/$(PROGRAM)
else ifeq ($(MODE), release)
    BUILD_DIR  := $(BUILD)/$(MODE)
    MODE_FLAGS := $(RELEASE_FLAGS)
    TARGET     := $(BIN)/$(MODE)/$(PROGRAM)
else ifeq ($(MODE), dist)
    BUILD_DIR  := $(BUILD)/$(MODE)
    MODE_FLAGS := $(DIST_FLAGS)
    TARGET     := $(BIN)/$(MODE)/$(PROGRAM)
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

# All
all: release debug

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
	strip $(TARGET) || true

# Main task
$(TARGET): $(OBJS)
	mkdir -p $(dir $@)
	$(CC) $(C_FLAGS) $(MODE_FLAGS) $(OBJS) -o $@ $(LDPATHS) $(LDFLAGS)

# Compile all cpp files
$(BUILD_DIR)/%.o: $(SRC)/%.$(EXT)
	mkdir -p $(dir $@)
	$(CC) $(C_FLAGS) $(MODE_FLAGS) $(PRE_FLAGS) $(INC_FLAGS) -c -o $@ $< $(LDPATHS) $(LDFLAGS)

# Compile db
db:
	compiledb make build

# Bear task
.PHONY: bear
bear:
	bear -- $(MAKE) build

# Package bin
.PHONY: package
package: dist
	tar -czvf $(BIN)/dist/$(PROGRAM)-$(VERSION).tar.gz -C $(BIN)/dist $(PROGRAM)

.PHONY: format
format:
	$(CLANG_FORMAT) -i $(FORMAT_FILES)

.PHONY: lint
lint:
	$(CLANG_TIDY) $(LINT_FILES) -- $(C_FLAGS) $(MODE_FLAGS) $(INC_FLAGS)

CLEAN_COMMON := compile_commands.json *.dSYM

# Clean task
.PHONY: clean
clean:
	$(RM) -r $(BUILD)/$(MODE) $(BIN)/$(MODE) $(CLEAN_COMMON)

# Clean all modes
clean_all:
	$(RM) -r $(BUILD) $(BIN) $(CLEAN_COMMON)

help:
	@echo "Available commands:"
	@echo "  make build       - Build the project"
	@echo "  make debug       - Build in debug mode"
	@echo "  make release     - Build in release mode"
	@echo "  make dist        - Build for distribution"
	@echo "  make clean       - Clean current mode"
	@echo "  make clean_all   - Clean all builds"
	@echo "  make format      - Format source files"
	@echo "  make lint        - Run lint checks"
	@echo "  make package     - Package the build for distribution"
	@echo " "
	@echo "Example usage:"
	@echo "  make build MODE=dist"
	@echo "  make run ARGS=\"arg1 arg1 ...\""

#@echo "  make test        - Run tests"

# Include all dependencies
-include $(DEPS)
