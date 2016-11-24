executable: objects
	g++ -pedantic -std=c++11 *.o -o main
	rm *.o
	@echo "------------------------Successful compilation!------------------------"
	./main
objects: *.cpp
	g++ -pedantic -std=c++11 -c *.cpp
