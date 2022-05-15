run: main.o funkcijos1.o
	g++ -o run.exe main.o funkcijos1.o -static-libgcc -static-libstdc++ -O1

funkcijos1.o: funkcijos1.cpp struct.h
	g++ -c funkcijos1.cpp

main.o: main.cpp struct.h
	g++ -c main.cpp

clean: 
	del *.o