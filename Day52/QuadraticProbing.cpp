// { Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
  public:
    //Function to fill the array elements into a hash table 
    //using Quadratic Probing to handle collisions.
    void QuadraticProbing(vector <int>&hash, int hashSize, int arr[], int N)
    {
        hash.assign(hashSize,-1);
        for(int i=0;i<N;i++)
        {
            if(hash[arr[i]%hashSize]==-1)
                hash[arr[i]%hashSize]=arr[i];
            else
            {
                int k=arr[i]%hashSize;
                int power = 1;
                while(hash[(k+power*power)%hashSize]!=-1)
                {
                    power++;
                }
                hash[(k+power*power)%hashSize]=arr[i];
            }
        }
    }


};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int hashSize;
	    cin>>hashSize;
	    
	    
	    int  N;
	    cin>>N;
	    int arr[N];
	    
	    for(int i=0;i<N;i++)
	    cin>>arr[i];
	    
	    vector<int> hash (hashSize);
	    Solution obj;
	    obj.QuadraticProbing (hash, hashSize, arr, N);
	    
	    for(int i = 0;i < hashSize; i++)
	    cout<<hash[i]<<" ";
	    
	    cout<<endl;
	    
	}
	return 0;
}


  // } Driver Code Ends