class Solution {
public:
    int k,n;
    
    vector<vector<int>> combinationSum3(int k, int n) {
        this->k = k;
        this->n = n;
        vector<int> cand = {1,2,3,4,5,6,7,8,9};
        return combinationSum(cand,n);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        fill(res,curr,0,candidates,target);
        return res;
    }
    void fill(vector<vector<int>>& res, vector<int> curr,int ind, vector<int>& cand,int target)
    {
        //base case
        if(!target)
        {   
            // cout<<"Reached\n";
            if(curr.size() == k)
                res.push_back(curr);
            return;
        }
        
        if(target<0 || ind>=cand.size())
                return;
        
        //Not Considering
        fill(res,curr,ind+1,cand,target);
        
        //considering elment at ind
        curr.push_back(cand[ind]);
        fill(res,curr,ind+1,cand,target-cand[ind]);
        
        //backTrack
        curr.pop_back();
    }
};