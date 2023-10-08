CFLAGS=-g -Wall -w
INCLUDE=-I ./include
LIBRARIES=-lm
OBJECTS=./bin/vec2.o

compile: compile_vec2
	gcc ${CFLAGS} ${INCLUDE} ./src/main.c ${OBJECTS} -L ./lib -lSDL2main -lSDL2 -o ./bin/main ${LIBRARIES}

compile_vec2:
	gcc ${CFLAGS} ${INCLUDE} -c ./src/vec2.c -o ./bin/vec2.o

run:
	./bin/main

clean:
	rm -rf ./bin/*