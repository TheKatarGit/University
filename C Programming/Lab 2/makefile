lab : main.o readFile.o count.o
	c99 -o lab main.o readFile.o count.o

main.o : main.c
	c99 -Wall -Werror -pedantic -c main.c

readFile.o : readFile.c
	c99 -Wall -Werror -pedantic -c readFile.c

count.o : count.c
	c99 -Wall -Werror -pedantic -c count.c

wipe :
	rm -f *.o lab *.gch
