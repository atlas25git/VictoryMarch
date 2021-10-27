class Solution {
    vector<vector<int>> ans;
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        vector<int> a;
        // sort(A.begin(),A.end());
        set<int>s(A.begin(),A.end());
        A.clear();
        vector<int> A1(s.begin(),s.end());
        sort(A1.begin(),A1.end(),greater<int>());
        fill(A1,B,a,A1.size());
        return ans;
    }
    
    void fill(vector<int>& A,int sum,vector<int> a,int i)
    {   
        if(!sum)
        {
            ans.push_back(a);
            // a.clear();
            return;
        }
        
        if(sum<0 || i<=0)return;
        
        
        // if(A[i-1]<=sum)
            // {
                a.push_back(A[i-1]);
                fill(A,sum-A[i-1],a,i);
                a.pop_back();
            // }
        fill(A,sum,a,i-1);
            
        // return;
    }
};