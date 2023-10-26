CFLAGS=-g -Wall -w
INCLUDE=-I ./include
LIBRARIES=-lm
OBJECTS=./bin/vec2.o ./bin/vec3.o ./bin/graphic.o

compile: compile_vec2 compile_vec3 compile_graphic
	gcc ${CFLAGS} ${INCLUDE} ./src/main.c ${OBJECTS} -L ./lib -lSDL2main -lSDL2 -o ./bin/main ${LIBRARIES}

compile_vec2:
	gcc ${CFLAGS} ${INCLUDE} -c ./src/vec2.c -o ./bin/vec2.o

compile_vec3:
	gcc $(CFLAGS) $(INCLUDE) -c ./src/vec3.c -o ./bin/vec3.o

compile_graphic:
	gcc $(CFLAGS) $(INCLUDE) -c ./src/graphic.c -o ./bin/graphic.o

run:
	./bin/main

clean:
	rm -rf ./bin/*