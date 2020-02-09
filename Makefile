all: FftRealPair.o main.o
	g++ FftRealPair.o main.o -o prog
	
FftRealPair.o: FftRealPair.cpp FftRealPair.hpp
	g++ -c FftRealPair.cpp
	
main.o: main.cpp
	g++ -c main.cpp
	
run:
	./prog
#./prog.exe if Windows/Cygwin

clean:
	rm *.o prog
# rm *.o prog.exe if Windows/Cygwin

#structure
#target: [dependencies list ...]
#	commands #starts with a tabulation
