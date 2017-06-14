all:p1

p1:p1.o 
	g++ -o p1 p1.o

p1.o:p1.cpp 
	g++ -c -std=c++11 p1.cpp

clean:
	rm -f p1 *.o
