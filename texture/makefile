LIBS = -lGLEW -lGL -lglfw -lSOIL

texprog: main.o texture.o
	g++ -g -Wall -o texprog main.o texture.o $(LIBS)
	
main.o: main.cpp texture.o
	g++ -g -Wall -c main.cpp $(LIBS)
	
texture.o: texture.cpp texture.h
	g++ -g -Wall -c texture.cpp $(LIBS)


.PHONY: clean	
clean:
	rm texprog main.o texture.o
