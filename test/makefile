run: test.o funkcijos1.o
	g++ -o run.exe test.o funkcijos1.o -static-libgcc -static-libstdc++ -O1

funkcijos1.o: funkcijos1.cpp struct.h
	g++ -c funkcijos1.cpp

test.o: test.cpp struct.h
	g++ -c test.cpp

clean: 
	del *.o