// How do you check if a given linked list contains a cycle? How do you find the starting node of the cycle?


#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 
struct node 
  { 
  int info; 
  struct node*link; 
  };  
 void iscycle(struct node *start) 
 {   
    int count=0; 
    struct node *fast,*slow;    
    fast=slow=start; 
    do 
    { 
       slow=slow->link; 
       fast=fast->link->link; 
    } 
    while(slow!=fast && fast!=NULL && fast->link!=NULL); 
    if(slow==fast) 
    printf("linked list contains cycle"); 
    else 
    { 
    printf(" Linked list doesn't contain cycle\n"); 
    return; 
    } 
       // finding node from where cycle starts... 
       slow=start; 
       while(slow!=fast) 
        { 
          fast=fast->link; 
          slow=slow->link; 
          } 
          printf("  \n\n Cycle starts at node %d \n",fast->info); 
 }  
int main() 
{ 
    double total_time;
    clock_t start, end;
   struct node *ptr,*temp; 
   ptr=(struct node *)malloc(sizeof(struct node )); 
   ptr->info=10; // Just allocated memory for the first node of linked_list. 
   temp=(struct node *)malloc(sizeof(struct node)); 
   temp->info=20; 
   ptr->link=temp; // allocated memory for second node and let it is pointed by link part of first node. 
   temp=(struct node *)malloc(sizeof(struct node)); 
   temp->info=30; 
   ptr->link->link=temp;//  allocated memory for third node and let it is pointed by link part of second node. 
    // similarly we have allocated memory for next 4 nodes . 
   temp=(struct node *)malloc(sizeof(struct node)); 
   temp->info=40; 
   ptr->link->link->link=temp; 
   temp=(struct node *)malloc(sizeof(struct node)); 
   temp->info=50; 
  ptr->link->link->link->link=temp; 
   temp=(struct node *)malloc(sizeof(struct node)); 
   temp->info=60; 
   ptr->link->link->link->link->link=temp; 
   temp=(struct node *)malloc(sizeof(struct node)); 
   //temp->info=70; 
   //ptr->link->link->link->link->link->link=temp;  
    //temp->link=ptr->link->link->link; // Here we have made cycle that is link part of last node is pointing to node fourth i.e we have added cycle in the list. 
   iscycle(ptr); 
    end = clock();
    total_time = ((double) (end - start)) / CLK_TCK;
    printf("\nTime taken : %f seconds\n", total_time);
    
   } 