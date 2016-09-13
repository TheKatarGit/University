pr : main.o maths.o InOut.o
	c99 -o pr main.o maths.o InOut.o

main.o : main.c
	c99 -Wall -Werror -pedantic -c main.c

InOut.o : InOut.c
	c99 -Wall -Werror -pedantic -c InOut.c

maths.o : maths.c
	c99 -Wall -Werror -pedantic -c maths.c

clean :
	rm -f *.o pr *.txt
