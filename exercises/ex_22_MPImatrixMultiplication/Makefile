CXX = mpicxx
MPIEXEC = mpiexec
MPIFLAGS = -np 2
DIFF ?= diff
CXXFLAGS += -Wall -std=c++11

EXE = main
OBJS = main.o dense_matrix.o matrix.o


main.o: dense_matrix.hpp
dense_matrix.o: dense_matrix.hpp matrix.hpp

.DEFAULT_GOAL = all
.PHONY: all build clean distclean check testclean

all: build

build: $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(LDLIBS) $^ $(OUTPUT_OPTION)

