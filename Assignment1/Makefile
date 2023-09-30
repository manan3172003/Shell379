process.o: process.cpp
	g++ process.cpp -o process.o

processtable.o: process.o processtable.cpp
	g++ processtable.cpp process.o -o processtable.o

helpers.o: helpers.cpp
	g++ helpers.cpp -o helpers

shell379:
	g++ shell379.cpp process.cpp helpers.cpp processtable.cpp -o shell379

clean:
	rm shell379

temp:
	g++ process.cpp processtable.cpp runner.cpp helpers.cpp shell379.cpp -Wall  -o shell379
