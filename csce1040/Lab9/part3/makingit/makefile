final: parse.o set.o stack.o db.o database.o bubble.o bSearch.o
	cc -o final parse.o set.o stack.o db.o database.o bubble.o bSearch.o
parse.o: parse.h defs.h db.h stack.h set.h sortAndSearch.h
	cc -c parse.c
bSearch.o: defs.h sortAndSearch.h set.h 
	cc -c bSearch.c
database.o:  defs.h parse.h set.h sortAndSearch.h db.h
	cc -c database.c
bubble.o: defs.h set.h sortAndSearch.h db.h
	cc -c bubble.c
stack.o: stack.h set.h 
	cc -c stack.c
db.o: defs.h set.h sortAndSearch.h db.h
	cc -c db.c
set.o: set.h db.h
	cc -c set.c
clean: 
	$(RM) final *.o *~
run:
	./final < data
