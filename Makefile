EXE=histo
OBJS=histo.o

CXXFLAGS = -O2 -std=c++17

$(EXE) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean :
	rm -f $(EXE) $(OBJS)
