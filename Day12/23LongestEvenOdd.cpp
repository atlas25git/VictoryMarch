// { Driver Code Starts
//Initial Template for C++
#include<iostream> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Function to find the length of longest subarray of even and odd numbers.
int maxEvenOdd(int arr[], int n) 
{ 
   int max_so_far = 1; 
   int curr_max = 1; 
   
   //Iterating over the array.
   for (int i = 1; i < n; i++) 
   { //since i is incremented by 1, therefore either of the or statement
   //would concur with the next step as i changes to i+1, if initaly it were 
   //triggering odd for as former, then in this iteration the 
   //or statement with first one being od would be bound to be triggered
      //Checking for alternate odd and even numbers.
      //In that case we update the counter and maximum length.
      if ((arr[i-1] %2 == 0 && arr[i] % 2 != 0) || 
         (arr[i-1] %2 != 0 && arr[i] % 2 == 0))
      {
        //Incrementing the counter.
		curr_max++; 
		//Updating the maximum length.
		max_so_far = max(max_so_far, curr_max); 
      }
      //Else if there is consecutive odd or even numbers,
      //we just update the counter as 1.
      else curr_max = 1;
   } 
   //returning the result.
   return max_so_far; 
} 
};

// { Driver Code Starts.
int main() 
{ 
    int testcases;
    //testcases
    cin>>testcases;
    while(testcases--)
    {
        int sizeOfArray;
        //size of array
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        
        //inserting elements in the array
        for(int i=0;i<sizeOfArray;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        //calling function
        cout  << ob.maxEvenOdd(arr, sizeOfArray)<<endl; 
    }
   return 0; 
} 
  // } Driver Code Ends