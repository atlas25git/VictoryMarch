// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
    //Function to fill the array elements into a hash table 
    //using Linear Probing to handle collisions.
    vector<int> linearProbing(int hashSize, int arr[], int sizeOfArray)
    {
        vector<int> hash(hashSize,-1);
        
    
    for(int i=0;i<sizeOfArray;i++)
    {
        if(hash[arr[i]%hashSize] == -1)
            hash[arr[i]%hashSize]=arr[i];
        else
        {
            int c=0,k=arr[i]%hashSize,flag=0;
            while(c<hashSize && hash[k]!=-1)
            {
                if(hash[k]==arr[i]){flag=1;break;}
                k=(k+1)%hashSize,c++;
            }
            if(flag)continue;
            //toChechk the circular dependecy check
            //as we're iterating the array in circular fashion
            if(c<hashSize)
                hash[k]=arr[i];
        }
    
    }
    return hash;
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
	    
	    int  sizeOfArray;
	    cin>>sizeOfArray;
	    int arr[sizeOfArray];
	    
	    for(int i=0;i<sizeOfArray;i++)
	    cin>>arr[i];
	    
	    vector<int> hash;
	    Solution obj;
	    hash = obj.linearProbing( hashSize, arr, sizeOfArray);
	    
	    for(int i=0;i<hashSize;i++)
	    cout<<hash[i]<<" ";
	    
	    cout<<endl;
	    
	    
	}
	return 0;
}

  // } Driver Code Ends