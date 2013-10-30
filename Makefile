main: main.o windmill.o cube.o
	g++ -Wall -g InitShader.cpp -framework OpenGL -framework GLUT -o main main.o cube.o windmill.o

main.o: main.cpp cube.h
	g++ -Wall -g -c main.cpp

windmill.o: windmill.cpp windmill.h
	g++ -Wall -g -c windmill.cpp

cube.o: cube.h cube.cpp
	g++ -Wall -g -c cube.cpp

clean:
	rm -f main main.o cube.o main.o
