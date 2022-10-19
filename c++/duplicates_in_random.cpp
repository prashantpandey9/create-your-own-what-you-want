#include <iostream>
#include <cstdlib>
#include <chrono>
#include <algorithm>


using namespace std;
using namespace std::chrono;
#define SIZE 10

void most_occurred(int nums[]){
    int max_count = 0;
  cout << "\nMost occurred number: ";
  for (int i=0; i<SIZE; i++)
  {
   int count=1;
   for (int j=i+1;j<SIZE;j++)
       if (nums[i]==nums[j])
           count++;
   if (count>max_count)
      max_count = count;
  }
  for (int i=0;i < SIZE;i++)
  {
   int count=1;
   for (int j=i+1; j < SIZE; j++)
       if (nums[i] == nums[j])
           count++;
   if (count==max_count)
       cout << nums[i] << endl;
  }
}

int main(){
    auto start = high_resolution_clock::now();
    int nums[SIZE];
    for(int i = 0; i < SIZE; i++){
        nums[i] = rand() % ( 63 - 25 + 1 );
    }

    for (int i = 0; i < SIZE; i++){
        // cout << "Random Number generated are :\n";
        cout << nums[i] << " ";
    }

    sort(nums, nums + SIZE);
    int counter = 0;
    for(int i = 0; i < SIZE; i++) {
        if(nums[i] == nums[i+1])
            counter++;
    }
    cout << "\n No. of Duplicates: " << counter;
    most_occurred(nums);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nTime: " << duration.count() << " microsecond"<< endl;
    cout << "" << endl; 
    cout << "" << endl;
    cout << "Name - Saiyam Gupta" << endl;
    return 0;
}