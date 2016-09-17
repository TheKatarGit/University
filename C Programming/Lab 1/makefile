pr : main.o maths.o InOut.o
	c99 -o pr main.o maths.o InOut.o

tests : maths.o InOut.o UnitTestScan.o UnitTestMaths.o unittests.o
	c99 -o tests maths.o InOut.o UnitTestScan.o UnitTestMaths.o unittests.o

main.o : main.c
	c99 -Wall -Werror -pedantic -c main.c

InOut.o : InOut.c
	c99 -Wall -Werror -pedantic -c InOut.c

maths.o : maths.c
	c99 -Wall -Werror -pedantic -c maths.c

unittests.o : unittests.c
	c99 -Wall -Werror -pedantic -c unittests.c

UnitTestScan.o : UnitTestScan.c
	c99 -Wall -Werror -pedantic -c UnitTestScan.c

UnitTestMaths.o : UnitTestMaths.c
	c99 -Wall -Werror -pedantic -c UnitTestMaths.c

clean :
	rm -f *.o pr *.txt *.gch
