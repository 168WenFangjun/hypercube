CXX = clang++
CXXFLAGS = -O3 -std=c++11 -g

all: alltest

allbin: hypercube.ex

alltest: hypercube.test

hypercube.test: hypercube.ex
	./hypercube.ex

hypercube.ex: main.cpp hypercube.hpp util.hpp
	$(LINK.cpp) $< $(LOADLIBES) $(LDLIBS) -o $@
