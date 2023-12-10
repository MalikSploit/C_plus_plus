SRC=$(wildcard *.cpp)
EXE=main

CXXFLAGS+=-Wall -Wextra -MMD -g -O2 -fdiagnostics-color=auto
LDFLAGS= #-lSDL

OBJ=$(addprefix build/,$(SRC:.cpp=.o))
# DEP=$(addprefix build/,$(SRC:.cpp=.d))

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

build/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf build $(EXE) core *.gch

-include $(DEP)
