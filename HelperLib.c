#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "HelperLib.h"
#include "Stack.h"
#include "Macros.h"

char * reverse(char * x)
{
   int index = 0;
   stk * x_stk = new_stack(MAX_DIGITS);
   char * x_cpy = malloc(sizeof(char) * MAX_DIGITS);

   strcpy(x_cpy, x);

   push(x_stk, '0');

   while(x_cpy[index])
   {
      push(x_stk, x_cpy[index]);
      ++index;
   }

   index = 0;

   while(!is_empty(x_stk))
   {
      x_cpy[index] = pop(x_stk);
      ++index;
   }
  
   delete_stack(x_stk);
   x = x_cpy;
   x_cpy = NULL;
   free(x_cpy);

   return x;   
}

int carry(int result)
{
   return result / CARRY;
}

int borrow(int result, char * x, int index)
{
   int borrow_from = ctod(x[index]);
   --borrow_from;
   x[index] = borrow_from;
   return CARRY;
}

int ctod(char x)
{
   if((x - CONVERTER) < 0)
      return -(x - CONVERTER);
   else
      return x - CONVERTER;
}

char dtoc(int x)
{
   return x + CONVERTER;
}

int cmp(char * x, char * y)
{
   int index = 0;
   int x_len = 0;
   int y_len = 0;

   while(x[index] || y[index])
   {
      if(x[index]) 
         ++x_len;
      if(y[index])
         ++y_len;

      ++index;
   }

   if(x_len > y_len)
      return 1;
   else if(x_len < y_len)
      return -1;
   else if(x_len == y_len)
   {
      index = 0;

      while(x[index] && y[index])
      {
         if(x[index] == y[index])
         {
            ++index;
            continue;
         }
         else
         {
            if(x[index] > y[index])
               return 1;
            else if(x[index] < y[index])
               return -1;
         }
      }

      return 0;
   }
}

void print_output(char * x)
{
   int index = 0;

   while(x[index + 1])
   {
      fputc(x[index], stdout);
      ++index;
   }

   fputc('\n', stdout);
}
