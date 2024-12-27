CFLAGS = -Wall -Werror -std=c99 -c

default: clean main.o fvector.o
	gcc -o bin/main obj/main.o obj/fvector.o
debug: clean main_debug.o fvector_debug.o
	gcc -o bin/main obj/main.o obj/fvector.o

clean:
	mkdir -p bin/ obj/
	rm -rf obj/*.o
	rm -rf bin/*

main.o: src/main.c
	gcc $(CFLAGS) $(LDLIBS) -O2 src/main.c -o obj/main.o
main_debug.o: src/main.c
	gcc $(CFLAGS) -ggdb $(LDLIBS) src/main.c -o obj/main.o

fvector.o: src/fvector.c src/fvector.h
	gcc $(CFLAGS) $(LDLIBS) -O2 src/fvector.c -o obj/fvector.o
fvector_debug.o: src/fvector.c src/fvector.h
	gcc $(CFLAGS) -ggdb $(LDLIBS) src/fvector.c -o obj/fvector.o
