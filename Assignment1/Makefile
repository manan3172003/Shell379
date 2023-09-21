process.o: process.cpp
	g++ process.cpp -o process.o

processtable.o: process.o processtable.cpp
	g++ processtable.cpp process.o -o processtable.o

shell379: shell379.cpp process.o processtable.o
	g++ shell379.cpp process.o processtable.o -o shell379

test: process.o
	gcc test.cpp process.o -o test

clean:
	rm *.o shell379_final