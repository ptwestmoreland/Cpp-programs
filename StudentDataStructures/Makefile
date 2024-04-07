FLAGS = -Wall

all: Driver.o Student.o
	g++ $(FLAGS) Driver.o Student.o -o Output.out

Student.o: Student.cpp
	g++ $(FLAGS) Student.cpp -c

Driver.o: Driver.cpp
	g++ $(FLAGS) Driver.cpp -c

run:
	./Output.out

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#
