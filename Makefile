CC = g++
CFLAGS = -Wall -pedantic -g
LDFLAGS = -lglut -lGLEW -lGLU -lGL -lm

main: main.o windmill.o cube.o InitShader.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

main.o: main.cpp InitShader.cpp Angel.h
	$(CC) $(CFLAGS) -c main.cpp InitShader.cpp $(LDFLAGS)

windmill.o: windmill.cpp windmillh
	$(CC) $(CFLAGS) -c $<

cube.o: cube.cpp cube.h
	$(CC) $(CFLAGS) -c cube.cpp InitShader.cpp $(LDFLAGS)

clean:
	rm -f *.o main
