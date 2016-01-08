/*==============================================================================
                                   Stack.c
 -------------------------------------------------------------------------------
 Author:      Jeremy Cruz

 Date:        8/22/15
 
 Description: This implements a stack data structure. Default functions are 
              present involve push, pop, and top.  There are also helper 
              functions involving status of the stack whether it is full or
              empty. These bool return values are determined by the occupancy
              of elements in the stack. There are also debug setters, and a 
              print method when debugging is on. This stack is specific to the
              char data type.
==============================================================================*/
#include<stdio.h>
#include<stdlib.h>
#include "Stack.h"

/*______________________________________________________________________________
 Name:        new_stack

 Parameters:  capacity: max amount of elements stack can hold

 Return:      new_stack: the stack struct that has been created

 Description: This function allocates memory for a stack pointer and a char 
              pointer that will contain elements within the stack. Current and
              max amount of entries for the stack are initialized.
______________________________________________________________________________*/
stk * new_stack(int capacity)
{
   stk * this_stack = malloc(sizeof(stk));   /* allocate memory for stack struct
                                              */
   this_stack->max_occ = capacity;           /* set maximum capacity */
   this_stack->occupancy = 0;                /* set current amount of entries */
   this_stack->the_stack = malloc(capacity); /* allocate memory for entries to 
                                                be placed into stack */
}

/*______________________________________________________________________________
 Name:        delete_stack

 Parameters:  stack: stack to be deleted

 Return:      void

 Description: This function deallocates all memory associated with the stack.
______________________________________________________________________________*/
void delete_stack(stk * stack)
{
   /* Free the stack and the array that contains stack elements */
   free(stack->the_stack);
   free(stack);
}

/*______________________________________________________________________________
 Name:        push

 Parameters:  stack: stack being pushed to
              x:     char being placed on stack
 
 Return:      x: char that was pushed onto stack

 Description: This function places a char onto the stack.
______________________________________________________________________________*/
char push(stk * stack, char x)
{
   char ret_val = '0'; /* default return value */

   /* condition to push */
   if(stack->occupancy < stack->max_occ)
   {
      stack->the_stack[stack->occupancy] = x;
      ++stack->occupancy;
      ret_val = x;
   }
   /* error message */
   else
      printf("ERROR: Pushing to full stack!\n");

   /* debugging */
   if(debug_mode)
      debug_print(stack);

   /* return value pushed to stack or '0' if full */
   return ret_val;
}

/*______________________________________________________________________________
 Name:        pop

 Parameters:  stack

 Return:      ret_val: value popped off the stack

 Description: This function removes the value on top of the stack and returns 
              it.
______________________________________________________________________________*/
char pop(stk * stack)
{
   char ret_val = '0'; /* default return value */

   /* condition to pop */
   if(stack->occupancy > 0)
   {
      ret_val = stack->the_stack[stack->occupancy - 1];
      stack->the_stack[stack->occupancy - 1] = '\0';
      --stack->occupancy;
   }
   /* error message */
   else
      printf("ERROR: Popping from empty stack!\n");

   /* debugging */
   if(debug_mode)
      debug_print(stack);

   /* return value popped from stack or '0' if empty */
   return ret_val;
}

/*______________________________________________________________________________
 Name:        top

 Parameters:  stack: stack returning top of from

 Return:      ret_val: top most value on stack

 Description: This function looks at the top of the stack and returns the value
              on it.
______________________________________________________________________________*/
char top(stk * stack)
{
   char ret_val = '0'; /* default return value */

   /* condition to top */
   if(stack->occupancy > 0)
      ret_val = stack->the_stack[stack->occupancy - 1];
   /* error message */
   else
      printf("ERROR: Topping from empty stack!\n");
   
   /* debugging */
   if(debug_mode)
      debug_print(stack);
   
   /* return top of stack or '0' if empty */
   return ret_val;
}

/*______________________________________________________________________________
 Name:        is_full

 Parameters:  stack: stack to test

 Return:      ret_val: boolean status of whether stack is full

 Description: Return boolean status of stack being full.
______________________________________________________________________________*/
int is_full(stk * stack)
{
   int ret_val = 0; /* default to false */

   /* condition to return true */
   if(stack->occupancy == stack->max_occ)
      ret_val = 1;

   /* return status */
   return ret_val;
}

/*______________________________________________________________________________
 Name:        is_empty        

 Parameters:  stack: stack to test

 Return:      ret_val: boolean status of whether stack is empty

 Description: Return boolean status of stack being empty.
______________________________________________________________________________*/
int is_empty(stk * stack)
{
   int ret_val = 0; /* default to false */

   /* condition to return true */
   if(stack->occupancy == 0)
      ret_val = 1;

   /* return status */
   return ret_val;
}

/*______________________________________________________________________________
 Name:        debug_off

 Parameters:  void

 Return:      void

 Description: Turn off debugging.
______________________________________________________________________________*/
void debug_off()
{
   /* set off debugging */
   debug_mode = 0; 
}

/*______________________________________________________________________________
 Name:        debug_on

 Parameters:  void

 Return:      void

 Description: Turn on debugging.
______________________________________________________________________________*/
void debug_on()
{
   /* set on debugging */
   debug_mode = 1;
}

/*______________________________________________________________________________
 Name:        debug_print

 Parameters:  stack: stack to print entries of

 Return:      void

 Description: Print the contents of the stack.
______________________________________________________________________________*/
void debug_print(stk * stack)
{
   int index = 0; /* starting index */

   /* loop through stack printing each entry */
   while(stack->the_stack[index])
   {
      fputc(stack->the_stack[index], stdout);
      fputc(' ', stdout);
      ++index;
   }
   
   /* end with a new line to keep output clean */
   fputc('\n', stdout);
}
