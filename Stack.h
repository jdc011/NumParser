struct Stack
{
   int max_occ;
   int occupancy;
   char * the_stack;
};

typedef struct Stack stk;

int debug_mode;

stk * new_stack(int capacity);
void delete_stack(stk * stack);
char push(stk * stack, char x);
char pop(stk * stack);
char top(stk * stack);
int is_full(stk * stack);
int is_empty(stk * stack);
void debug_on();
void debug_off();
void debug_print(stk * stack);
