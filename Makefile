# Makefile for building the Wayland wrapper and the game
#
# Layout:
#   - src/      : .cpp files
#   - include/  : .hpp files
#   - build/    : objects and generated protocol files
#   - root      : Makefile, README.md, DOCUMENTATION.md, report.pdf, final executable
#
# Commands:
#   make         Build the game
#   make clean   Remove build artifacts and executable

# Tools
CXX      := g++
CC       := gcc
SCANNER  := wayland-scanner

# Directories
SRC_DIR    := src
INC_DIR    := include
BUILD_DIR  := build

# Flags
CXXFLAGS := -std=c++20 -Wall -Wextra -O2 -I$(INC_DIR) -I$(BUILD_DIR) -pthread -MMD -MP
CFLAGS   := -O2 -I$(INC_DIR) -I$(BUILD_DIR)
LDFLAGS  := -pthread -lwayland-client -lxkbcommon

# XDG-shell protocol XML
XDG_XML  := /usr/share/wayland-protocols/stable/xdg-shell/xdg-shell.xml

# Generated files go into build/
XDG_HDR  := $(BUILD_DIR)/xdg-shell-client-protocol.h
XDG_SRC  := $(BUILD_DIR)/xdg-shell-protocol.c
XDG_OBJ  := $(BUILD_DIR)/xdg-shell-protocol.o

# C++ source files in src/
CXX_SRCS := $(SRC_DIR)/Window.cpp \
            $(SRC_DIR)/game.cpp \
            $(SRC_DIR)/Player.cpp \
            $(SRC_DIR)/Obstacle.cpp \
            $(SRC_DIR)/Kebab.cpp \
            $(SRC_DIR)/PickupObstacle.cpp \
            $(SRC_DIR)/Coffee.cpp \
            $(SRC_DIR)/EnergyDrink.cpp \
            $(SRC_DIR)/DamagingObstacle.cpp \
            $(SRC_DIR)/Garbage.cpp \
            $(SRC_DIR)/BoltScooter.cpp \
            $(SRC_DIR)/DrunkStudent.cpp \
            $(SRC_DIR)/ObstacleSpawner.cpp \
            $(SRC_DIR)/GameRenderer.cpp \
            $(SRC_DIR)/Game.cpp \
            $(SRC_DIR)/windowManager.cpp \
            $(SRC_DIR)/Health.cpp

# Object files go into build/
CXX_OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(CXX_SRCS))

# Dependency files generated automatically
DEPS := $(CXX_OBJS:.o=.d)

# Final executable stays at root
TARGET   := game

.PHONY: all clean directories

all: directories $(TARGET)

directories:
	mkdir -p $(BUILD_DIR)

# Final link: executable at root
$(TARGET): $(XDG_OBJ) $(CXX_OBJS)
	$(CXX) $^ $(LDFLAGS) -o $@

# Every C++ object depends on generated protocol header
$(CXX_OBJS): $(XDG_HDR)

# Compile C++ source from src/ to build/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | directories
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile generated C source
$(XDG_OBJ): $(XDG_SRC) | directories
	$(CC) $(CFLAGS) -c $< -o $@

# Generate protocol header
$(XDG_HDR): $(XDG_XML) | directories
	$(SCANNER) client-header $< $@

# Generate protocol C source
$(XDG_SRC): $(XDG_XML) | directories
	$(SCANNER) private-code $< $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

-include $(DEPS)