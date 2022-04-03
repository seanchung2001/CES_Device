test: test.cc DBManager.o
	g++ -o test test.cc DBManager.o

DBManager.o: DBManager.h DBManager.cc
	g++ -c DBManager.cc

clean:
	rm -f test *.o