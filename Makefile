tktr: src/tktr.cpp src/cli.cpp
	g++ --std=c++11 -Wall -O2 -o tktr src/*.cpp

clean:
	rm -f *.o tktr

