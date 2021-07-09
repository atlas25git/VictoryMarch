// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    
    void fill(vector<int> arr,int n,vector<vector<int>>& res,vector<int> cur,int ind)
    {
        //Base case:
        if(ind==n)
        {
            res.push_back(cur);
            return;
        }
        
        int ni = ind+1;
        //counting repetitive elements
        while(ni<n && arr[ni]==arr[ind])ni++;
        int count = ni-ind;
        
        //Not including ind;
        fill(arr,n,res,cur,ni);
        
        //including ind
        for(int i=1;i<=count;i++)
        {
            for(int j=0;j<i;j++)
                cur.push_back(arr[ind]);
                
                fill(arr,n,res,cur,ni);
            
            for(int j=0;j<i;j++)
                cur.pop_back();
        }
    }
    
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        vector<vector<int>> res;
        vector<int> cur;
        sort(arr.begin(),arr.end());
        fill(arr,n,res,cur,0);
        sort(res.begin(),res.end());
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends