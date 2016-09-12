float get_avegarge(float ArrayOfNumbers[], int *i)
{
  int j;
  int sum = 0;
    for (j = 0; j < *i; j++) {
      sum += ArrayOfNumbers[j];
    };
  return sum/(*i);
};
