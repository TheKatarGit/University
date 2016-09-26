make tests -s
echo "1 2 3 4 5 6 7 8 9 10 " > test1.txt
echo "0.72 12 -4 -5.71 0 12 45 " > test2.txt
./tests
rm test1.txt
rm test2.txt
make clean -s
