#include <string.h>
#include "stack.h"

/**
 * @param int argc - arguments count, equals to one when no arg is passed
 * @param char* argv - arguments values, where argv[0] refers to the program name
 */
int main(int argc, char *argv[])
{
   if (argc != 2) {
      printf("É necessário informar exatamente uma sequência de parênteses/colchetes entre aspas\n");
      return 1;
   }

   char *seq = argv[1];
   int i = 0;

   Stack *p = create_stack(strlen(seq));

   while (seq[i] != '\0')
   {
      if ((seq[i] == '(') || (seq[i] == '['))
      {
         p = push(p, seq[i]);
      }
      else if (seq[i] == ')')
      {
         if (empty_stack(p) || top(p) != '(')
         {
            printf("mal formada\n");
            return 0;
         }
         p = pop(p);
      }
      else if (seq[i] == ']')
      {
         if (empty_stack(p) || top(p) != '[')
         {
            printf("mal formada\n");
            return 0;
         }
         p = pop(p);
      }
      i++;
   }
   if (empty_stack(p))
   {
      printf("bem formada\n");
   }
   else
   {
      printf("mal formada\n");
   }
   return 0;
}
