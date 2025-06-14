CC=g++
OMPFLAG=

# Get all .cpp files in the current directory
CPP_FILES := $(wildcard *.cpp)

# Generate the names of the output programs
PROGRAMS := $(CPP_FILES:.cpp=)

.PHONY: all build test dirs

all: build
	@echo "Creating all case study files"

build: dirs $(PROGRAMS)

dirs:
	@-mkdir bin >& /dev/null

# Rule to build each program
%: %.cpp
	$(CC) -O3 -g --std=c++20 -I ../../include -I ../../../include $(OMPFLAG) -o bin/$@ $<
	$(CC) -O3 -g --std=c++20 -DFAR_USE_C_INDEX -I ../../include -I ../../../include $(OMPFLAG) -o bin/$@_co $<

# Clean target to remove all generated programs
clean:
	rm -rf bin
