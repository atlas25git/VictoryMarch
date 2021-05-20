// { Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    { 
    	
    	// we basically use division theorem and modulo operations here
    	//for the even indices we store elements from the last 
    	//since array is sorted it'd be all of them maximums
    	//we use max_element+1 for our modulo operations
    	//and we multiply the no at max_idx with moduloFactor and 
    	//to get it we put modulous 
    	
    	int maxI = n-1,minI=0;
    	int maxE = arr[maxI];//to calculate modulo factor
    	int mF = arr[n-1]+1;//cout<<mF;
    	
    	for(int i=0;i<n;i++)
    	{
    	    if(!(i&1))//maxElemets
    	    {
    	        arr[i] += (arr[maxI]%mF)*mF;
    	        maxI--;
    	        //cout<<arr[i]<<" ";
    	    }
    	    else
    	    {
    	        arr[i] += (arr[minI]%mF)*mF;
    	        minI++;
    	    }
    	    
    	}
    	    
    	    for(int i=0;i<n;i++)
    	    {   //cout<<arr[i]<<" ";
    	        arr[i] = arr[i]/mF;
    	    }
    	
    	
    	 
    }
};

// { Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 
  // } Driver Code Ends