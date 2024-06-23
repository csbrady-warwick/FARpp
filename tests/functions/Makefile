FC=g++

# Get all .cpp files in the current directory
CPP_FILES := $(wildcard *.cpp)

# Generate the names of the output programs
PROGRAMS := $(CPP_FILES:.cpp=)

.PHONY: all build test dirs

all:
	@echo "Type 'make test' to build and run tests. Type 'make build' to build test programs but not run them"

# Default target to build all programs
test: build
	./run.sh

build: dirs $(PROGRAMS)

dirs:
	@-mkdir bin >& /dev/null
	@-rm run.sh >& /dev/null
	@echo "#! /bin/bash" > run.sh
	@chmod +x run.sh

# Rule to build each program
%: %.cpp
	$(FC) -O3 -g -Wall -Wextra --std=c++20 -I ../../include -I ../include -o bin/$@ $<
	@echo "./bin/"$@ >> run.sh

# Clean target to remove all generated programs
clean:
	rm -rf bin
	rm run.sh
