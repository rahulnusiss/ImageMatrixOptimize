
output: main.o Search.o TestSearch.o FileHandle.o
	g++ main.o Search.o TestSearch.o FileHandle.o -o output.out

main.o: main.cpp
	g++ -c main.cpp

Search.o: Search.cpp Search.h
	g++ -c Search.cpp

TestSearch.o: TestSearch.cpp TestSearch.h
	g++ -c TestSearch.cpp

FileHandle.o: FileHandle.cpp FileHandle.h
	g++ -c FileHandle.cpp

clean:
	rm *.o output

# target: dependencies
#	action