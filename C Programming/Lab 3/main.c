#include "stdlib.h"
#include "stdio.h"

struct Data
{
   int a;
};
struct List
{
   struct Data d;
   struct List *next;
};

void Print(struct List *u)
{
   struct List *p = u;
   printf("List: ");
   while(p)
   {
      printf("%d\n",p->d.a);
      p = p->next;
   }
}



int main(int argc, char const *argv[]) {
  

  return 0;
}
