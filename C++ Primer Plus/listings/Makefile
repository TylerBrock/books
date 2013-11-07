CC=clang++
CFLAGS=-Wall -std=c++11

use_stuc: use_stuc.o studentc.o
	$(CC) $(CFLAGS) use_stuc.o studentc.o -o use_stuc

use_stuc.o:
	$(CC) $(CFLAGS) -c use_stuc.cpp

studentc.o:
	$(CC) $(CFLAGS) -c studentc.cpp

clean:
	rm -fr *.o a.out use_stuc
