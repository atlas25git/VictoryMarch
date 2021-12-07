class Solution {
    vector<vector<int>> ans;
    int n;
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        //Approach: Include exclude principle as we used in finding unordered sets in unbounded 
        //knapsack problems, here what we aim at is that we move the index even if we're considering
        //or not considering the present item.
        //The only difference that arises here is that we need to perform exclude operation for each
        //count of repetitive elements considered.
        this->n = c.size();
        sort(c.begin(),c.end());
        fill(c,target,vector<int>(),0);
        return ans;
    }
    
    void fill(vector<int>& c,int target,vector<int> curr,int ind)
    {
        if(!target)
        {
            ans.push_back(curr);
            return;
        }
        if(target<0 || ind>=n)return;
        
        int count = 1;
        for(int i=ind+1;i<n;i++)
            if(c[ind] == c[i])count++;
        
        //exclude
        fill(c,target,curr,ind+count);
        //include
        for(int i=1;i<=count;i++)
        {   int j;
            for(j=0;j<i;j++)
                curr.push_back(c[ind]);
            fill(c,target-c[ind]*j,curr,ind+count);
         
            for(int k=0;k<j;k++)
                curr.pop_back();
        }
        return;
    }
};