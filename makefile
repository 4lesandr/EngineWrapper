CXX = g++
CXXFLAGS = -std=c++11 -Wall
DEPS = Engine.h Wrapper.h Subject.h FileReader.h
OBJ = main.o Engine.o Wrapper.o Subject.o FileReader.o

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

main: $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f *.o main