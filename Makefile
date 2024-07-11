

all:
	gcc -c ./src/bookList.c -I ./include/ -o ./obj/bookList.o
	gcc main.c ./obj/*.o -I ./include/ -o ./bin/main

clean:
	rm ./obj/* ./bin/*