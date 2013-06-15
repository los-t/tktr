tktr: src/tktr.cpp
	g++ --std=c++11 -Wall -O2 -o tktr src/tktr.cpp

clean:
	rm -f *.o tktr

