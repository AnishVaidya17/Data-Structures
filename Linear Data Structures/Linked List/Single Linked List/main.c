//This program implements singley linked list


#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node* link;

};

struct node* root = NULL;
int len;
void append(void);
void prepend(void);
int length();
void delete();
void display();
void addafter();

void main()
{
   int ch;

   while(1)
   {
      printf("\n\n\nSingle linked list operations.\n");
      printf("\n1. Append\n");
      printf("\n2. Prepend\n");
      printf("\n3. Addafter\n");
      printf("\n4. Length\n");
      printf("\n5. Display\n");
      printf("\n6. Delete\n");
      printf("\n7. Quit\n");

      printf("\nEnter your choice: ");
      scanf("%d", &ch);

      switch (ch)
      {
      case 1:
         append();
         break;
      
      case 2:
         prepend();
         break;

      case 3:
         addafter();
         break;

      case 4:
         len = length();
         printf("\nLength: %d\n", len);
         break;   
      
      case 5:
         display();
         break;

      case 6: 
         delete();
         break;

      case 7:
         printf("\nProgram Terminated!!\n");
         exit(0);      
      
      default:
         printf("\nInvalid choice!!\n\n");
         break;
      }
   }
}



void append()                 
{
   struct node* temp;

   temp = (struct node*)malloc(sizeof(struct node));

   printf("\nEnter node data: ");
   scanf("%d", &temp->data);
   temp->link = NULL;

   if(root == NULL)           
      root = temp;            

   else 
   {
      struct node* p;               
      p = root;                     

      while(p->link != NULL)             
         p = p->link;                      

      p->link = temp;                     
   }                                      
}




void prepend()                
{
   struct node* temp;

   temp = (struct node*)malloc(sizeof(struct node));
   printf("\nEnter node data: ");
   scanf("%d", &temp->data);
  
   temp->link = NULL;

   if(root == NULL)              
      root = temp;

   else
   {
      temp->link = root;
      root = temp;
   }
      
}





int length()                              
{
   struct node* temp;
   int count=0;

   temp = root;                

   while(temp != NULL)
   {
      count++;
      temp = temp->link;           
   }
   return count;
}
 




void display()
{
   struct node* temp;
   temp = root;

   if(temp == NULL)
      printf("\nList is empty!!\n");

   else
   {
      printf("\nList is: ");
      while(temp != NULL)
      {
         printf("%d--> ", temp->data);
         temp = temp->link;
      }

      printf("\n\n");
   }
      
}




void addafter()
{
   struct node* temp, *p;
   int loc, len, i=1;
   display();
   printf("\nEnter a location to add: ");
   scanf("%d", &loc);
   len = length();
   
   if(loc > len)
   {
      printf("\nInvalid location!");
      printf("\nList has %d nodes.", len);
   }
   else
   {
      p =root;
      while(i < loc)
      {
         p = p->link;
         i++;
      }

      temp = (struct node*)malloc(sizeof(struct node));

      printf("\nEnter node data: ");
      scanf("%d", &temp->data);
      temp->link = NULL;

      temp->link = p->link;
      p->link = temp;
   }
   
}




void delete()
{
   struct node* temp;
   int loc;
   printf("\nEnter location to delete: ");
   scanf("%d", &loc);

   if(loc > length())
      printf("\nInvalid location!!");

   else if(loc == 1)       
   {
      temp = root;
      root = temp->link;      

      temp->link = NULL;      
      free(temp);
   }   

   else
   {
      struct node* p = root, *q;
      int i = 1;

      while(i< loc)
      {
         p = p->link;
         i++;
      }
      q = p->link;               
      p->link = q->link;         
      
      q->link = NULL;            
      free(q);
   }
   
}
