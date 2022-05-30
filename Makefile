all:
	g++ -c -g main.cpp
	g++ -g -o main main.o
debug:
	g++ -g -o main main.cpp
clean:
	del ./*.obj
	del ./*.o
run:
	./main.exe