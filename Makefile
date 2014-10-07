all: libnvidiathing.so

GTK=`pkg-config --cflags gtk+-2.0`

%.o: %.c
	echo $(GTK)
	gcc $(GTK) -fPIC -c -Wall $*.c -o $*.o

libnvidiathing.so: preload.o
	gcc -shared preload.o -ldl -o libnvidiathing.so

clean:
	rm -f *.o *.so
