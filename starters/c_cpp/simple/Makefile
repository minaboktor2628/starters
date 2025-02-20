CC := gcc
LIB := 
TARGET := <executable>
SRC := src
BUILD := build
EXT := c
C_FLAGS := -Wall -Wextra -g 
PRE_FLAGS := -MMD -MP

CPP_FILES := $(wildcard $(SRC)/*.$(EXT))
OBJ_FILES := $(patsubst $(SRC)/%.$(EXT), $(BUILD)/%.o, $(CPP_FILES))
DEP_FILES := $(OBJ_FILES:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(C_FLAGS) $(OBJ_FILES) -o $@ $(LIB) $(PRE_FLAGS)

$(BUILD)/%.o: $(SRC)/%.$(EXT)
	@mkdir -p $(BUILD)
	$(CC) $(C_FLAGS) -c $< -o $@ $(PRE_FLAGS)

-include $(DEP_FILES)

clean:
	rm -rf $(BUILD) $(TARGET)
