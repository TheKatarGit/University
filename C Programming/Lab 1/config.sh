if [ -e "InOut.h" ] && [ -e "maths.h" ] && [ -e "main.c" ]; then
  make pr
  rm -f old_numbers.txt || true
  touch old_numbers.txt
  gedit old_numbers.txt
  ./pr
  gedit old_numbers.txt new_numbers.txt
  rm -f new_numbers.txt || true
  rm -f old_numbers.txt || true
  make clean
else
  echo 'Some libraries are absent.'
fi
