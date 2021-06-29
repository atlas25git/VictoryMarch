// { Driver Code Starts
// A Sample C++ program for beginners with Competitive Programming

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    
    // A[]: input array
    // N: input array
    //Function to sort the binary array.
    void binSort(int arr[], int N)
    {
       //Your code here
       
       /**************
        * No need to print the array
        * ************/
        // int nsz = -1;
        // for(int i=0;i<N;i++)
        // {
        //     if(arr[i]==0)
        //     {
        //         nsz++;
        //         swap(arr[nsz],arr[i]);
        //     }
        // }
        
        int i=-1,j=N;
        
        while(true)
        {
            do{
                i++;
            }while(arr[i]==0);
            do{
                j--;
            }while(arr[j]==1);
            if(j<i)return;
            swap(arr[i],arr[j]);
        }
        
    }
};

// { Driver Code Starts.
int main() {
	int T;
	cin>>T;
	// Input the number of testcases
	while(T--)
	{
	    int N;
	    cin>>N; //Input size of array N
	    int A[N]; 
	    
	    for(int i = 0; i  < N; i++)
	      cin>>A[i];
	      
	    Solution obj;
	    obj.binSort(A,N);
	    
	    for(int x:A)
	    cout<<x<<" ";
	      
	    cout<<endl;
	}
	return 0;
}



  // } Driver Code Ends