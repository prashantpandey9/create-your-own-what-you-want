

#include<stdio.h>
#include<stdlib.h>

struct item
{
    int item_no;
    int price;
    int weight;
};

void input(struct item* arr , int n)
{
    printf("Enter the price and weight of %d items : \n\n",n);

    for(int i=0;i<n;i++)
    {
        printf("Price of item %d : ",(i+1));
        scanf("%d",&(arr+i)->price);

        printf("Weight of item %d : ",(i+1));
        scanf("%d",&(arr+i)->weight);

        (arr+i)->item_no = (i+1);

        printf("\n");
    }
}

void display(struct item* arr , int n)
{
    printf("LIST OF ITEMS : \n");

    for(int i=0 ; i<n ;i++)
    {
        printf("Item  %d  ---  Price : Rs. %d , Weight : %d kg \n",(arr+i)->item_no , (arr+i)->price , (arr+i)->weight);
    }
    printf("\n");
}

//sort the items as per descending order of value per unit weight (value / weight)
void sort(struct item* arr , int n)
{
    int i,j,t;

    for(i=0;i<n;i++)
    {

        for(j=i+1;j<n;j++)
        {
            double p1 = ((double)((arr+i)->price)) / (arr+i)->weight;
            double p2 = ((double)((arr+j)->price)) / (arr+j)->weight;

            if( p1 < p2)
            {
                t = (arr+i)->item_no;
                (arr+i)->item_no = (arr+j)->item_no;
                (arr+j)->item_no = t;

                t = (arr+i)->price;
                (arr+i)->price = (arr+j)->price;
                (arr+j)->price = t;

                t = (arr+i)->weight;
                (arr+i)->weight = (arr+j)->weight;
                (arr+j)->weight = t;
            }
        }
    }
    
}

void fractionalKnapsack(struct item* arr , int n , int knapsack_capacity)
{

    //sorting the items in descending order of value per unit weight
    sort(arr,n);

    printf("\nAFTER SORTING : \n");
    display(arr,n);


    int profit = 0;

    //initially, the capacity of storage = size of knapsack
    int current_capacity = knapsack_capacity;

    printf("Items included : \n");

    for(int i=0; i<n ; i++)
    {
        if((arr+i)->weight <= current_capacity)
        {
            profit = profit + (arr+i)->price;
            current_capacity = current_capacity - (arr+i)->weight;

            printf("%d kg of %d item has been included of price Rs. %d \n",(arr+i)->weight , (arr+i)->item_no , (arr+i)->price);
        }

        else
        {
            profit = profit + ( (arr+i)->price / (arr+i)->weight ) * current_capacity;
            int m = ( (arr+i)->price / (arr+i)->weight ) * current_capacity;
            printf("%d kg of Item %d has been included of price Rs. %d \n",current_capacity , (arr+i)->item_no , m);
            current_capacity = 0;
        }
    }

    printf("\nMAXIMUM PROFIT EARNED : Rs. %d \n",profit);

}

int main()
{
    int n,knapsack;

    printf("Enter the number of items available : \n");
    scanf("%d",&n);

    struct item* arr = (struct item*)malloc(n*sizeof(struct item));

    input(arr,n);

    printf("Enter the size of the Knapsack : \n");
    scanf("%d",&knapsack);

    printf("BEFORE SORTING : \n");
    display(arr,n);

    fractionalKnapsack(arr,n,knapsack);

    return 0;
}
