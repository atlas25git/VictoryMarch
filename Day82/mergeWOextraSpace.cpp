 int nextGap(int gap)
        {
            if(gap<=1)
                return 0;
            return ceil((double)((double)gap/2));// + (gap%2);
        }
        
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
             int i,j,gap=m+n;
             
             for(gap=nextGap(gap);gap>0;gap=nextGap(gap))
             {
                 for(i=0;i+gap<n;i++)
                    if(arr1[i]>arr1[i+gap])
                        swap(arr1[i],arr1[i+gap]);
                        
                //if gap>n then the relative positon of gap in 2nd array would be
                //n-gap as on the scale of n+m
                 for(j=gap>n?gap-n:0; i<n && j<m; i++,j++)
                 //here i is persisted with the index it stopped in the upper loop
                 //and j is already gap ahead, therefore incrementing both by 1 would
                 //effectively be checking elements gap apart
                     if(arr1[i]>arr2[j])
                        swap(arr1[i],arr2[j]);
                 if(j<m)
                 {
                     for(j=0;j+gap<m;j++)
                     if(arr2[j]>arr2[j+gap])
                        swap(arr2[j],arr2[j+gap]);
                 }
                 
             }
        }

        // { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        
        int nextGap(int n)
        {
            if(n<=1)return 0;
            return (n/2+n%2);
        }
        
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int i,j,gap;
            
            for(gap=nextGap(m+n);gap>0;gap = nextGap(gap))
            {
                //first array
                
                for(i=0;i+gap<n;i++)
                    if(arr1[i]>arr1[i+gap])
                        swap(arr1[i],arr1[i+gap]);
                
                //2nd array
                //if gap<n then last posn of i will be gap-1 dis apart, plus now
                //in second array thus will gain the parity
                for(j=gap>n?gap-n:0;j<m && i<n;j++,i++)
                    if(arr1[i]>arr2[j])swap(arr1[i],arr2[j]);
                
                ///if(j<m)
                //{
                    for(j=0;j+gap<m;j++)
                        if(arr2[j]>arr2[j+gap])
                            swap(arr2[j],arr2[j+gap]);
                        
                //}
                    
            }
        } 
};

// { Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 
  // } Driver Code Ends