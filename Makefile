all:main.o matrix_data.o function_implement.o
	g++ -std=c++11 -pthread -o main main.o matrix_data.o function_implement.o
main.o:main.cpp
	g++ -c main.cpp
matrix_data.o:matrix_data.cpp
	g++ -c matrix_data.cpp
function_implement.o:function_implement.cpp
	g++ -c function_implement.cpp
clean:
	rm -rf *.o main
