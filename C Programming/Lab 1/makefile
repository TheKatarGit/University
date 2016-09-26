pr : main.o maths.o InOut.o delete.o
	c99 -o pr main.o maths.o InOut.o delete.o

tests : maths.o InOut.o UnitTestScan.o UnitTestMaths.o UnitTestDelete.o unittests.o delete.o
	c99 -o tests maths.o InOut.o UnitTestScan.o UnitTestMaths.o UnitTestDelete.o unittests.o delete.o

main.o : main.c
	c99 -Wall -Werror -pedantic -c main.c

InOut.o : InOut.c
	c99 -Wall -Werror -pedantic -c InOut.c

maths.o : maths.c
	c99 -Wall -Werror -pedantic -c maths.c

delete.o : delete.c
	c99 -Wall -Werror -pedantic -c delete.c

unittests.o : unittests.c
	c99 -Wall -Werror -pedantic -c unittests.c

UnitTestScan.o : UnitTestScan.c
	c99 -Wall -Werror -pedantic -c UnitTestScan.c

UnitTestMaths.o : UnitTestMaths.c
	c99 -Wall -Werror -pedantic -c UnitTestMaths.c

UnitTestDelete.o : UnitTestDelete.c
	c99 -Wall -Werror -pedantic -c UnitTestDelete.c

clean :
	rm -f *.o pr *.txt *.gch
