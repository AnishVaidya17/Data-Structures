//This program uses stack to reverse a string


#include<stdio.h>
#include<string.h>

#define MAX 20

int top = -1;
char stack[MAX];


char push(char item)       
{
   
   if(top == MAX-1)
      printf("\nStack is full!!");
   else
      return stack[++top] = item; 
}



char pop()              
{
   if(top == -1)
      printf("\nThe stack is empty!!");
   else 
      return stack[top--];   
}
   


int main()
{
   int i;
   char str[MAX];
   printf("\nThis program reverses the given string using stack.\n\n");
   printf("\nEnter a string: ");
   gets(str);

   for(i=0; i<strlen(str); i++)
      push(str[i]);

   for(i=0; i<strlen(str); i++)
      str[i] = pop();

   printf("\nThe reversed string is: %s", str);
        
   return 0;
}

