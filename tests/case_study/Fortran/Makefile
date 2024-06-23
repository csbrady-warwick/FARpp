FC=gfortran

# Get all .cpp files in the current directory
F90_FILES := $(wildcard *.f90)

# Generate the names of the output programs
PROGRAMS := $(F90_FILES:.f90=)

.PHONY: all build test dirs

all: build
	@echo "Creating all case study files"

build: dirs $(PROGRAMS)

dirs:
	@-mkdir bin >& /dev/null

# Rule to build each program
%: %.f90
	$(FC) -O3 -g -o bin/$@ $<

# Clean target to remove all generated programs
clean:
	rm -rf bin
