EXENAME = main
TEMPLATE_DEPS = Vertex.h Vertex.hpp Edge.h Edge.hpp

CXX = clang++
#CXX = g++
CXXFLAGS = -std=c++14 -g -O1 -Wall -Wextra

all : $(EXENAME)

$(EXENAME): $(TEMPLATE_DEPS) main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(EXENAME)

.PHONY: clean
clean:
	rm -rf *.o $(EXENAME) *.dSYM
