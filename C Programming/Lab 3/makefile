lab : main.o readFile.o list.o replacer.o
	@c99 -o lab main.o readFile.o list.o replacer.o

main.o : main.c
	@c99 -Wall -Werror -pedantic -c main.c

readFile.o : readFile.c
	@c99 -Wall -Werror -pedantic -c readFile.c

list.o : list.c
	@c99 -Wall -Werror -pedantic -c list.c

replacer.o : replacer.c
	@c99 -Wall -Werror -pedantic -c replacer.c

wipe :
	@rm -f *.o lab *.gch
