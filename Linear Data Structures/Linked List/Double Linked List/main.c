#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node* left;
   struct node* right;
};

struct node* root = NULL;


void append()
{
   struct node* temp;
   temp = (struct node*)malloc(sizeof(struct node));           //size allocation for temp
                                                               //this creates a new node
   printf("\nEnter the node data: ");
   scanf("%d", &temp->data);

   temp->left = NULL;                                          //the left and right of node to be null
   temp->right = NULL;

   if(root == NULL)                                            //if list is empty
      root = temp;

   else                                                        //if list is not empty
   {
      struct node* p = root;

      while(p->right != NULL)
         p = p->right;

      p->right = temp;                                         //add of new node in last node

      temp->left = p;                                          //add of prev node in left of new node

   }

}  //append ends


void prepend()
{
   struct node* temp;
   temp = (struct node*)malloc(sizeof(struct node));

   printf("\nEnter the node data: ");
   scanf("%d", &temp->data);

   temp->left = NULL;
   temp->right = NULL;

   if(root == NULL)
      root = temp;

   else
   {
      temp->right = root;                                       //the add of first node to new node
      root->left = temp;                                        //add of new first to left of prev first
      root = temp;                                              //new add to root
   }
      
}  //prepend ends


int length()                                                   //for length of list
{
   struct node* temp = root;
   int count = 0;

   while(temp != NULL)
   {
      count++;
      temp = temp->right;
   }
   //printf("\nThe length is: %d\n", count);
   return count;

}


void display()
{
   struct node* temp = root;
   
   if(temp == NULL)
      printf("\nThe list is empty!!\n");

   else
   {
      while(temp != NULL)
      {
         printf("%d -->", temp->data);
         temp = temp->right;
      }
   }
      
}  //display ends here



void addafter()                                             //to add after a node
{
   struct node* temp, *p;
   int loc, len, i = 1;
   printf("\nEnter location at which to add: ");
   scanf("%d", &loc);

   len = length();                                          //calling length function

   if(loc > len)
   {
      printf("\nInvalid location!!");
      printf("\nThe list contains %d nodes\n", len);
   }

   else
   {
      temp = (struct node*)malloc(sizeof(struct node));

      printf("\nEnter node data: ");
      scanf("%d", &temp->data);

      temp->left = NULL;
      temp->right = NULL;

      p = root;
      while(i < loc)
      {
         p = p->right;
         i++;

         p->right->left = temp;                              //give add of new node to next node
         temp->left = p;                                     //give add of prev node to new node
         p->right = temp;                                    //give add of new node to prev node  
      }
   }
   
}  //addafter ends here



void delete()
{
   struct node* temp;
   int loc, len;
   
   printf("\nThe list is: ");
   display();
   printf("\nEnter location to be deleted: ");
   scanf("%d", &loc);
   

   if(loc > len)                                      //if loc greater than length
      printf("\nInvalid location!!\n");

   else if(loc == 1)                                  //if loc = first node
   {
      temp = root;
      root = temp->right;

      root->left = NULL;
      temp->right = NULL;
      free(temp);
   }

   else                                               //any node from list
   {
      struct node* p = root, *q;
      int i = 1;
      while(i < loc-1)
      {
         p = p->right;
         i++;
      }

      q = p->right;                                   //q starts pointing to the mentioned node

      p->right = q->right;                            //next node's add to prev node
      q->right->left = p;                             //add of prev node to next node
     
      q->left = NULL;                                 //disconnect left from prev node      
      q->right = NULL;                                //disconnect right from next node
      free(q);
   }
   
      
}  //delete ends here



void main()
{
   int ch, len;
   
   while(1)
   {
      printf("\n\nDouble Linked List operations!!!\n");
      printf("\n1. Append");
      printf("\n2. Prepend");
      printf("\n3. Add after");
      printf("\n4. Length");
      printf("\n5. Delete");
      printf("\n6. Display");
      printf("\n7. Exit\n");
      printf("\nEnter your choice: ");
      scanf("%d", &ch);

      switch(ch)
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
               printf("\nThe length of list is: %d", len);
               break;

         case 5: 
               delete();
               break;

         case 6:
               display();
               break;

         case 7:
               exit(0);


         default: printf("\nInvalid choice!!");                              
      }
      
   }
}     //main ends here