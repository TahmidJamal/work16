all: work16.o
	gcc -o out work16.o

work16.o: work16.c
	gcc -c work16.c

run:
	./out

clean:
	rm out
	rm *.o
