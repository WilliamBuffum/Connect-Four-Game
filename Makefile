connect_four.exe: connect_four.o main.o
	g++ connect_four.o main.o -o play

connect_four.o:
	g++ -c connect_four.cpp

main.o:
	g++ -c main.cpp

clean:
	rm -f *.o *.out *.exe play
