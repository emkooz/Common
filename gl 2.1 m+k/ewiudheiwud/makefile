LIBS = -lGLEW -lGL -lglfw -lSOIL

Engine: test.o
	g++ -g -Wall -o Engine test.o $(LIBS)
	
test.o: test.cpp Camera.o
	g++ -g -Wall -c test.cpp $(LIBS)
	
Camera.o: Camera.cpp Camera.h
	g++ -g -Wall -c Camera.cpp $(LIBS)

	
clean:
	rm Engine test.o Camera.o
