
output: main.o TestSearch.o FileHandle.o Sequence.o Unordered.o BestMatch.o Utils.o
	g++ -std=c++11 main.o TestSearch.o FileHandle.o Sequence.o Unordered.o BestMatch.o Utils.o -o output.out

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

ISearch.o: ISearch.h
	g++ -std=c++11 -c ISearch.h

Sequence.o: Sequence.h Sequence.cpp
	g++ -std=c++11 -c Sequence.cpp

Unordered.o: Unordered.h Unordered.cpp
	g++ -std=c++11 -c Unordered.cpp

BestMatch.o: BestMatch.h BestMatch.cpp
	g++ -std=c++11 -c BestMatch.cpp

TestSearch.o: TestSearch.cpp TestSearch.h
	g++ -std=c++11 -c TestSearch.cpp

FileHandle.o: FileHandle.cpp FileHandle.h
	g++ -std=c++11 -c FileHandle.cpp

Utils.o: Utils.cpp Utils.h
	g++ -std=c++11 -c Utils.cpp

clean:
	rm *.o output

# target: dependencies
#	action