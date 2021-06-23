/*
 * C Program to Implement a Queue using an Array (FIFO)
 */
#include<stdio.h>
#include<stdlib.h>
 
#define MAX 50
 
void enqueue();
void dequeue();
void display();
int queue_array[MAX];
int rear = - 1;
int front = - 1;

int main()
{
    int ch;
    while (1)
    {
        printf("\n\n---Queue Functions---\n");
        printf("\n1.Insert element  \n\n");
        printf("2.Delete element  \n\n");
        printf("3.Display \n\n");
        printf("4.Quit \n\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        
        switch (ch)
        {
            case 1:
                enqueue();
                break;
            
            case 2:
                dequeue();
                break;
            
            case 3:
                display();
                break;
            
            case 4:
                printf("\nProgram Terminated!\n");
                exit(0);
            
            default:
                printf("Wrong choice \n");
        } 
    } 
    return 0;
}//main ends here 
 


void enqueue()
{
    int add_item;
    if (rear == MAX - 1)
        printf("\nQueue Overflow! \n");
    
    else
    {
        if (front == - 1)
        /*If queue is initially empty */
        front = 0;
        printf("\nEnter the element : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
} 
 


void dequeue()
{
    if (front == - 1 || front > rear)
    {
        printf("\nQueue Underflow! \n");
        return ;
    }
    else
    {
        printf("\nElement deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
} 
 


void display()
{
    int i;
    if (front == - 1)
        printf("\nQueue is empty!! \n");
    else
    {
        printf("\n The Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
} 