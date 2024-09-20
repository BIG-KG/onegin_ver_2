all: hello
	hello
hello: main.o in_out_strings.o sorting.o work_with_file.o work_with_elements.o
	g++ main.o in_out_strings.o sorting.o work_with_file.o work_with_elements.o -o hello

main.o: main.cpp
	g++ -c main.cpp
	
work_with_elements.o: work_with_elements.cpp
	g++ -c work_with_elements.cpp
	
work_with_file.o: work_with_file.cpp
	g++ -c work_with_file.cpp

in_out_strings.o: in_out_strings.cpp
	g++ -c in_out_strings.cpp
	
sorting.o: sorting.cpp
	g++ -c sorting.cpp

clean:
	rm -rf *.o hello