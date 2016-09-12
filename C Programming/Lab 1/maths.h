void get_avegarge(float ArrayOfNumbers[], int *i, float *avg)
{
  int j;
  int sum = 0;
    for (j = 0; j < *i; j++) {
      sum += ArrayOfNumbers[j];
    };
  *avg = sum/(*i);
}
