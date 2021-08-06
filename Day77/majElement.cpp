// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /* Function to find the candidate for Majority */
    int findCandidate(int a[], int size) 
    {   //Moore's voting algo, garuntees to return element having more than half the freq.
        //If it ain't made a point that there'll all be a majority element, we'll have to check up
        //we ckeep count for particular elements, increasing them for same occr, 
        //and decreasing for diff, if becomes 0 we choose other element 
        int mj = 0;
        int count = 1;
        
        for(int i=1;i<size;i++)
        {
            if(a[mj] == a[i])count++;
            else count--;
            if(count == 0)
            {
                mj = i,count =1;
            }
        }
        return a[mj];
    }
    
    
    /* Function to check if the candidate 
       occurs more than n/2 times */
    bool isMajority(int a[], int size, int cand) 
    { 
        int count = 0; 
        for (int i = 0; i < size; i++) 
            if (a[i] == cand) 
                count++; 
              
        if (count > size/2) 
            return 1; 
          
        else
            return 0; 
    } 
    
    
    /* Function to print Majority Element */
    int majorityElement(int a[], int size)
    {
        /* Find the candidate for Majority*/
       int cand = findCandidate(a, size); 
      
       /* Print the candidate if it is Majority*/
        if (isMajority(a, size, cand)) 
            return cand;
        else
            return -1;
    }

};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends



class Solution{
  public:
    /* Function to find the candidate for Majority */
    int findCandidate(int a[], int size) 
    { 
        int maj_index = 0, count = 1; 
        
        // use linear search to compute candidate for majority element
        for (int i = 1; i < size; i++) 
        { 
            
            if (a[maj_index] == a[i]) 
                count++; 
            else
                count--; 
            if (count == 0) 
            { 
                maj_index = i; 
                count = 1; 
            } 
        } 
        return a[maj_index]; 
    }
    
    
    /* Function to check if the candidate 
       occurs more than n/2 times */
    bool isMajority(int a[], int size, int cand) 
    { 
        int count = 0; 
        for (int i = 0; i < size; i++) 
            if (a[i] == cand) 
                count++; 
              
        if (count > size/2) 
            return 1; 
          
        else
            return 0; 
    } 
    
    
    /* Function to print Majority Element */
    int majorityElement(int a[], int size)
    {
        /* Find the candidate for Majority*/
       int cand = findCandidate(a, size); 
      
       /* Print the candidate if it is Majority*/
        if (isMajority(a, size, cand)) 
            return cand;
        else
            return -1;
    }

};