cc = g++

HW5: Homework5.o Functions.o
	cc -o HW5 Homework5.o Functions.o
Functions.o: class.h Prototypes.h
	cc -c Functions.cpp
Homework5.o: class.h Prototypes.h
	cc -c Homework5.cpp
clean: 
	$(RM) HW5 *.o *~
