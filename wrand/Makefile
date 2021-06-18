all: libwrand.a test

libwrand.a: wrand.o
	ar rcs libwrand.a wrand.o

wrand.o: wrand.c wrand.h
	gcc -c wrand.c -o wrand.o

test: test.c wrand.h
	gcc test.c -o test -I. -L. -lwrand

.PHONY: clean

clean:
	rm wrand.o libwrand.a test

