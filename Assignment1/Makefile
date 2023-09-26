process.o: process.cpp
	g++ process.cpp -o process.o

processtable.o: process.o processtable.cpp
	g++ processtable.cpp process.o -o processtable.o

shell379:
	g++ shell379.cpp process.cpp processtable.cpp -o shell379

test: process.cpp processtable.cpp
	g++ test.cpp process.cpp processtable.cpp -o test

clean:
	rm shell379 test

temp:
	g++ process.cpp processtable.cpp runner.cpp helpers.cpp shell379.cpp -Wall  -o shell379