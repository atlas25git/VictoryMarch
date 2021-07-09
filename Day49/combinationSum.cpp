// { Driver Code Starts



#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution 
{
    public:
    
    void fill(vector<int> &A,int B,vector<vector<int>> &v,vector<int> &v1,int i)
    {
        if(B==0)
        {
            v.push_back(v1);
            return;
        }
        while(i<A.size() && B-A[i]>=0)
        {
            v1.push_back(A[i]);
            fill(A,B-A[i],v,v1,i);
            i++;
            v1.pop_back();
        }
    }
    
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        //sort
        sort(A.begin(),A.end());
        //remove duplicates
        A.erase(unique(A.begin(),A.end()),A.end());
        vector<vector<int>> v;
        vector<int> v1;
        fill(A,B,v,v1,0);
        return v;
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
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
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
}	  // } Driver Code Ends