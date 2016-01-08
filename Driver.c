#include<stdio.h>
#include "OperationsLib.h"
#include "Stack.h"

void debug_setter(int, char * const *);

int main(int argc, char * const * argv)
{
   debug_setter(argc, argv);

   //printf("%d\n", gcf(3768, 1701));

   //pfnum(10000);
   //fputc('\n', stdout);

   char * a = "987641612612984619846129461294612983476192846129461293476129869845619847617612947612761261923476198237461924";
   char * b = "14293476298629356293462394623945762394857623946239762394762984298429847629847629847629846298469239623984762394576239485762394876239457623947623947623984763249876";
   
   print_output(add(a, b));
   //printf("%d\n", cmp(a, b));
   return 0;
}

void debug_setter(int arg1, char * const * arg2)
{
   char option;

   debug_off();

   while((option = getopt(arg1, arg2, "x")) != EOF)
   {
      switch(option)
      {
         case 'x':
            debug_on();
         break;
      }
   }
}
