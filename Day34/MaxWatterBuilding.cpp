// { Driver Code Starts
//Initial Template for C++


// C++ implementation of the approach 
#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to return the maximum water that can be stored.
    int maxWater(int height[], int n) 
    {   
        int max1=0;
        int i=0,j=n-1;
        while(i<j)
        {
            if(height[i]<height[j])
            {
                max1 = max(max1,(j-i-1)*height[i]);
                i++;
            }
            
            else if(height[j]<height[i])
            {
                max1 = max(max1,(j-i-1)*height[j]);
                j--;
            }
            else{
                max1=max(max1,(j-i-1)*height[i]);
                i++,j--;
            }
        }
    
        return max1;
    } 
};



// { Driver Code Starts.

// Driver code 
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int height[n];
        
        for(int i=0;i<n;i++)
        {
            cin>>height[i];
        }
        Solution ob;
        cout<<(ob.maxWater(height, n))<<endl;
    }

	 
} 

  // } Driver Code Ends