FC=g++

# Get all .cpp files in the current directory
CPP_FILES := $(wildcard *.cpp)

# Generate the names of the output programs
PROGRAMS := $(CPP_FILES:.cpp=)

.PHONY: all build test dirs

all: build
	@echo "Creating all tutorial files"

build: dirs $(PROGRAMS)

dirs:
	@-mkdir bin >& /dev/null

# Rule to build each program
%: %.cpp
	$(FC) -O3 -g -Wall -Wextra --std=c++20 -I ../../include -I ../include -o bin/$@ $<

# Clean target to remove all generated programs
clean:
	rm -rf bin
