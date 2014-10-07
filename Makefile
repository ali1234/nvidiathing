all: libnvidiathing.so

%.o: %.c
	gcc -fPIC -c -Wall $*.c -o $*.o

libnvidiathing.so: preload.o
	gcc -shared preload.o -ldl -o libnvidiathing.so

clean:
	rm -f *.o *.so
