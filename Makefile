# A Makefile for compiling small SDL projects

CC := g++
CCFLAGS := -std=c++20 `sdl2-config --libs --cflags` -lSDL2_image -lSDL2 
HDRS := $(wildcard *.h)

EXEC := test
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:%.cpp=%.o)

# default recipe
all: $(EXEC)

# recipe for building object files
%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

# recipe for building the final executable
$(EXEC): $(OBJS)
	$(CC) $(CCFLAGS) $< -o $@

debug: $(CCFLAGS) += -g
debug: all

# recipe to clean the workspace
clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean debug
