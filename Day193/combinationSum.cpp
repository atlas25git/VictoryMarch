class Solution {
    vector<vector<int>> ans;
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        vector<int> a;
        // sort(A.begin(),A.end());
        auto cmp = [](int a,int b){return a>b;};
        
        set<int,decltype(cmp)>s(cmp);
        for(auto x: A)s.insert(x);
        A.clear();
        A.resize(s.size());
        copy(s.begin(),s.end(),A.begin());
        // for(auto x: s)A.emplace_back(x);
        // cout<<A.size();
        fill(A,B,a,A.size());
        return ans;
    }
    
    void fill(vector<int>& A,int sum,vector<int> a,int i)
    {   
        if(!sum)
        {
            ans.push_back(a);
            return;
        }
        
        if(sum<0 || i<=0)return;
        
        a.push_back(A[i-1]);
        fill(A,sum-A[i-1],a,i);
        a.pop_back();
        fill(A,sum,a,i-1);
    }
};