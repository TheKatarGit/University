make wipe
make lab
echo "1 1 2 3 4 5" > "input.txt"
valgrind --leak-check=full --show-leak-kinds=all ./lab "input.txt"
make wipe
