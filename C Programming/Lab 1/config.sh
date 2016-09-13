if [ -e "InOut.h" ] && [ -e "maths.h" ] && [ -e "main.c" ]; then
  gcc -Wall -Werror -std=c99 -pedantic main.c
  rm -f old_numbers.txt || true
  touch old_numbers.txt
  gedit old_numbers.txt
  ./a.out
  gedit old_numbers.txt new_numbers.txt
  rm -f new_numbers.txt || true
  rm -f old_numbers.txt || true
else
  echo 'Some libraries are absent.'
fi
