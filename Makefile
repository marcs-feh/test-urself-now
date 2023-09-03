CC=clang
CXX=clang++

.PHONY: all clean

all:
	$(CC) example.c -o test-c.bin
	$(CXX) example.cpp -o test-c++.bin

clean:
	rm -f *.bin
