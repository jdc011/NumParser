#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "OperationsLib.h"
#include "HelperLib.h"
#include "Stack.h"
#include "Macros.h"

char * add(char * x, char *y)
{
   char * parsed_char_result = malloc(sizeof(char) * MAX_DIGITS);
   char * parsed_x = malloc(sizeof(char) * MAX_DIGITS);
   char * parsed_y = malloc(sizeof(char) * MAX_DIGITS);
   char * result = NULL;
   int x_dec;
   int y_dec;
   int parsed_int_result;
   int carry_amt = 0;
   int index = 0;


   strcpy(parsed_x, x);
   strcpy(parsed_y, y);

   if(parsed_x[0] == '-' && parsed_y[0] != '-')
   {
      parsed_x[0] = '\0';
      index = 1;

      while(parsed_x[index])
      {
         parsed_x[index - 1] = parsed_x[index];
         ++index;
      }

      parsed_x[index - 1] = '\0';

      result = sub(parsed_x, parsed_y);
   }
 
   if(x[0] != '-' && y[0] == '-')
   {
      y[0] = '\0';
      index = 1;

      while(y[index])
      {
         y[index - 1] = y[index];
         ++index;
      }

      y[index - 1] = '\0';

      result = sub(parsed_x, parsed_y);
   }

   if(parsed_x[0] == '-' && parsed_y[0] == '-')
   {
      index = 1;

      while(parsed_x[index])
      {
         parsed_x[index - 1] = parsed_x[index];
         ++index;
      }

      parsed_x[index - 1] = '\0';
      index = 1;

      while(parsed_y[index])
      {
         parsed_y[index - 1] = parsed_y[index];
         ++index;
      }

      parsed_y[index - 1] = '\0';

      parsed_char_result[0] = '-';
   }

   if(result != NULL)
   {
      free(parsed_x);
      free(parsed_y);
      return result;
   }

   free(parsed_x);
   free(parsed_y);

   x = reverse(x);
   y = reverse(y);

   while(x[index] || y[index])
   {
      if(x[index] == '\0')
         x_dec = 0;
      else
         x_dec = ctod(x[index]);

      if(y[index] == '\0')
         y_dec = 0;
      else
         y_dec = ctod(y[index]);
      
      parsed_int_result = (x_dec + y_dec + carry_amt) % CARRY;
      parsed_char_result[index] = dtoc(parsed_int_result);

      if((x_dec + y_dec + carry_amt) >= CARRY)
         carry_amt = carry(x_dec + y_dec + carry_amt);
      else if(carry_amt != 0)
         carry_amt = 0;

      ++index;
   }

   if(parsed_char_result[index - 1] == '0')
      parsed_char_result[index - 1] = '\0';

   result = reverse(parsed_char_result);
   free(parsed_char_result);
   
   return result;
}

char * sub(char * x, char * y)
{
   char * parsed_char_result = malloc(sizeof(char) * MAX_DIGITS);
   char * parsed_x = malloc(sizeof(char) * MAX_DIGITS);
   char * parsed_y = malloc(sizeof(char) * MAX_DIGITS);
   char * result = NULL;
   int x_dec;
   int y_dec;
   int parsed_int_result;
   int borrow_amt = 0;
   int index = 0;

   strcpy(parsed_x, x);
   strcpy(parsed_y, y);

   /*if(parsed_x[0] == '-' && parsed_y[0] != '-')
   {
      parsed_x[0] = '\0';
      index = 1;

      while(parsed_x[index])
      {
         parsed_x[index - 1] = parsed_x[index];
         ++index;
      }

      parsed_x[index - 1] = '\0';

      return sub(parsed_x, parsed_y);
   }
 
   if(x[0] != '-' && y[0] == '-')
   {
      y[0] = '\0';
      index = 1;

      while(y[index])
      {
         y[index - 1] = y[index];
         ++index;
      }

      y[index - 1] = '\0';

      return sub(parsed_x, parsed_y);
   }

   if(parsed_x[0] == '-' && parsed_y[0] == '-')
   {
      index = 1;

      while(parsed_x[index])
      {
         parsed_x[index - 1] = parsed_x[index];
         ++index;
      }

      parsed_x[index - 1] = '\0';
      index = 1;

      while(parsed_y[index])
      {
         parsed_y[index - 1] = parsed_y[index];
         ++index;
      }

      parsed_y[index - 1] = '\0';

      parsed_char_result[0] = '-';
   }*/

   if(result != NULL)
   {
      free(parsed_x);
      free(parsed_y);
      return result;
   }

   free(parsed_x);
   free(parsed_y);

   x = reverse(x);
   y = reverse(y);

   while(x[index] || y[index])
   {
      if(x[index] == '\0')
         x_dec = 0;
      else
         x_dec = ctod(x[index]);

      if(y[index] == '\0')
         y_dec = 0;
      else
         y_dec = ctod(y[index]);
      
      parsed_int_result = borrow_amt + (x_dec - y_dec);
      parsed_char_result[index] = dtoc(parsed_int_result);

      /*if((x_dec + y_dec + carry_amt) >= CARRY)
         carry_amt = carry(x_dec + y_dec + carry_amt);
      else if(carry_amt != 0)
         carry_amt = 0;*/

      ++index;
   }

   if(parsed_char_result[index - 1] == '0')
      parsed_char_result[index - 1] = '\0';

   result = reverse(parsed_char_result);
   free(parsed_char_result);
   
   return result;
}

char * mul(char * x, char * y)
{
   char ** parsed_char_result = malloc(sizeof(char *) * MAX_DIGITS);
   char * result = NULL;
   int x_dec;
   int y_dec;
   int parsed_int_result;
   int carry_amt = 0;
   int index = 0;
   int p_index = 0;

   for(index = 0; index < MAX_DIGITS; ++index)
      parsed_char_result[index] = malloc(sizeof(char) * MAX_DIGITS);

   x = reverse(x);
   y = reverse(y);

   while(x[index] || y[p_index])
   {
      if(x[index] == '\0')
         x_dec = 0;
      else
         x_dec = ctod(x[index]);

      if(y[p_index] == '\0')
         y_dec = 0;
      else
         y_dec = ctod(y[p_index]);

      parsed_int_result = (carry_amt + (y_dec * x_dec)) % CARRY;
      parsed_char_result[p_index][index] = dtoc(parsed_int_result);

      if(carry_amt + (y_dec * x_dec))
         carry_amt = carry(carry_amt + (x_dec * y_dec));
      else if(carry_amt != 0)
         carry_amt = 0;

      if(!x[index])
      {
         index = 0;
         ++p_index;
      }
      else
         ++index;
   }

   p_index = 0;

   print_output(parsed_char_result[p_index]);
   print_output(parsed_char_result[p_index + 1]);

   while(parsed_char_result[p_index])
   {
      //result = add(parsed_char_result[p_index], 
      //                     parsed_char_result[p_index + 1]);
      ++p_index;
   }

   return result;
}

char * dvd(char * x, char * y)
{
   return "01";
}

void pfnum(int lim)
{
   int * results = malloc(sizeof(int) * lim);
   int * factors;
   int test_num;
   int index;
   int sum;
   int results_occupancy = 0;
   int saved_index;

   for(test_num = 1; test_num <= lim; ++test_num)
   {
      index = 0;
      sum = 0;
      factors = malloc(sizeof(int) * lim);

      int start;

      for(start = 1; start <= test_num; ++start)
      {
         if(test_num % start == 0 && start != test_num)
         {
            factors[index] = start;
            ++index;
         }

         saved_index = index;
      }

      for(index = 0; index <= saved_index; ++index)
      {
         if(factors[index] < factors[index - 1])
            break;
         else
            sum += factors[index];
      }

      if(sum == test_num)
      {
         results[results_occupancy] = test_num;
         ++results_occupancy;
      }

      free(factors);
   }

   for(index = 0; index < results_occupancy; ++index)
      printf("%d ", results[index]);

   free(results);   
}

int gcf(int x, int y)
{
   int more;
   int less;

   if(x == y)
      return x;

   if(x > y)
   {
      more = x;
      less = y;
   }
   else
   {
      more = y;
      less = x;
   }

   int temp = more;
   more = less;
   less = temp % more;

   if(less == 0)
      return more;
   else
      return gcf(more, less);
}
