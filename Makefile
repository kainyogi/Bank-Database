all:homework3bV2

homework3bV2: main.o database.o userfunctions.o
	gcc -o homework3bV2 main.o database.o userfunctions.o

main.o: main.c record.h prototypes.h
	gcc -ansi -pedantic-errors -Wall -c main.c

database.o: database.c record.h prototypes.h
	gcc -ansi -pedantic-errors -Wall -c database.c

userfunctions.o: userfunctions.c record.h prototypes.h
	gcc -ansi -pedantic-errors -Wall -c userfunctions.c

clean:
	rm homework3bV2 main.o database.o userfunctions.o core.*
