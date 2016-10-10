echo "1 1 1 1 1" > "test1.txt"
echo " " > "test2.txt"
make testRead
./test
rm test1.txt
rm test2.txt
make wipe
