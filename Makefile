all: hello
	hello
hello: main.o in_out_strings.o sorting.o
	g++ main.o in_out_strings.o sorting.o -o hello

main.o: main.cpp
	g++ -c main.cpp

in_out_strings.o: in_out_strings.cpp
	g++ -c in_out_strings.cpp
	
sorting.o: sorting.cpp
	g++ -c sorting.cpp

clean:
	rm -rf *.o hello