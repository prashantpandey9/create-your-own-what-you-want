// How do you find the third node from the end in a singly linked list?

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct node
{
   int data;
   struct node *next;
} * head, *temp;
int count = 0;
void insert(int val)
{
   struct node *newnode = (struct node *)malloc(sizeof(struct node));
   newnode->data = val;
   newnode->next = NULL;
   if (head == NULL)
   {
      head = newnode;
      temp = head;
      count++;
   }
   else
   {
      temp->next = newnode;
      temp = temp->next;
      count++;
   }
}
void display()
{
   if (head == NULL)
      printf("no node ");
   else
   {
      temp = head;
      while (temp != NULL)
      {
         printf("%d ", temp->data);
         temp = temp->next;
      }
   }
}
void last(int n)
{
   int i;
   temp = head;
   for (i = 0; i < count - n; i++)
   {
      temp = temp->next;
   }
   printf("\n\n%drd node from the end of linked list is : %d", n, temp->data);
}
int main()
{
   double total_time;
   clock_t start, end;
   struct node *head = NULL;
   int n = 3;
   insert(50);
   insert(12);
   insert(3);
   insert(36);
   insert(8);
   printf("\nlinked list is : ");
   display();
   last(n);
   printf("\n\n");
   end = clock();
   total_time = ((double)(end - start)) / CLK_TCK;
   printf("\nTime taken : %f seconds\n", total_time);
 
   return 0;
}