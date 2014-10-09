all: libnvidiathing.so

%.o: %.c
	gcc -m32 -fPIC -c -Wall $*.c -o $*.o

libnvidiathing.so: preload.o
	gcc -m32 -shared preload.o -ldl -o libnvidiathing.so

clean:
	rm -f *.o *.so
