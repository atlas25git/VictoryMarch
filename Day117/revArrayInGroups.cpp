class Solution{
public:
    //Function to reverse every sub-array group of size k.
    
    void revUtil(int l,int r, vector<long long>& arr,int n)
    {   
        if(r>=n)r=n-1;
        
        while(l<r){
            swap(arr[l],arr[r]);
            l++;r--;
        }
    }
    
    void reverseInGroups(vector<long long>& arr, int n, int k){
        int i=0,j=k;
        while(i<n)
        {
            revUtil(i,j-1,arr,n);
            i+=k,j+=k;
        }
    }
};