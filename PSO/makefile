CXX	 := g++ -ggdb -O3
SRCS	 := main.cpp PSO.cpp 

OBJS	 := $(SRCS:.cpp=.o)
EXEC	 := run

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) -o $(EXEC) $(OBJS)

$(OBJS): $(SRCS)

dep:
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -M $(SRCS) > .depend

clean:
	-rm -rf *.o *.txt ../LIB/*.o $(EXEC) .depend

sinclude .depend