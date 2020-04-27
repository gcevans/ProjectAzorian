EXENAME = main
TEMPLATE_DEPS = Vertex.h Vertex.hpp Edge.h Edge.hpp Graph.h Graph.hpp graph_algo.h graph_algo.hpp

CXX = clang++
CXXFLAGS = -std=c++14 -g -O1 -Wall -Wextra

all : $(EXENAME)

$(EXENAME): $(TEMPLATE_DEPS) main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(EXENAME)

.PHONY: clean
clean:
	rm -rf *.o $(EXENAME) *.dSYM
