// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        int me = 0,count=1;
        for(int i=1;i<size;i++)
        {
            if(a[me] == a[i])count++;
            else count--;
            
            if(!count)
            {
                me=i;
                count=1;
            }
        }
        
        count=0;
        me=a[me];
        for(int i=0;i<size;i++)
        {
            if(a[i]==me)count++;
            if(count>size/2)return me;
        }
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