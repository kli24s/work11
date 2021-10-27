all: work11.o
	gcc -o work11m work11.o

work11.o: work11.c
	gcc -c work11.c

run:
	./work11m

clean:
	rm *.o
	rm *.txt
	rm work11m
