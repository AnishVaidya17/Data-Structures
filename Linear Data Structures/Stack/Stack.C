/*This program implements stack*/


#include<stdio.h>
#include<stdlib.h>

#define MAX 5					//Maximum number of elements that can be stored

int top=-1, stack[MAX];

void push();					//declaring the functions
void pop();
void peek();
void display();




int main()
{
	int ch;

	while(1)	
	{
		printf("\n\n*** Stack Menu ***");
		printf("\n\n1.Push\n2.Pop\n3.Display\n4.Peek\n5.Exit");
		printf("\n\nEnter your choice:");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: push();
					break;
			case 2: pop();
					break;
			case 3: display();
					break;
			case 4: peek();
				   break;
			case 5: exit(0);

			default: printf("\nInvalid Choice!!");
		}
	}

   return 0;
}






void push()
{
	int val, j=0;

	if(top==MAX-1)
	{
		printf("\n**Stack is full!!**\n\n");
	}
	else
	{
		printf("\nEnter an element to push:");
	   scanf("%d",&val);
      top = top+1;
		stack[top]=val;
		 
	}

}






void pop()
{
	if(top==-1)
	{
		printf("\nStack is empty!!\n\n");
	}
	else
	{
		printf("\nDeleted element is: %d", stack[top]);
		top=top-1;
	}
}







void peek()						//tells you where the top is
{
	if(top==-1)
		printf("\nStack is empty.\n\n");
	else
		printf("The top is at: %d", stack[top]);
		
}







void display()
{
	int i;

	if(top==-1)
	{
		printf("\nStack is empty!!\n\n");
	}
	else
	{
		printf("\nStack is: \n");
		for(i=top;i>=0;--i)
			printf("%d\n", stack[i]);
	}
}
