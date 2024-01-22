SRC=$(wildcard *.cpp)
EXE=cpp10

#decommentez le flag std avec clang++ sous mac m1
CXXFLAGS+=-Wall -Wextra -MMD -g -O2 #-std=c++11
LDFLAGS= #-lSDL

OBJ=$(addprefix build/,$(SRC:.cpp=.o))
DEP=$(addprefix build/,$(SRC:.cpp=.d))

$(EXE): $(OBJ)
	$(CXX) -o $(EXE) $^ $(LDFLAGS)

build/%.o: %.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf build core *.gch

-include $(DEP)
