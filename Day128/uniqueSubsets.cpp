class Solution
{
    public:
    
    void asu(vector<int>& arr,int sz,int ind,vector<vector<int>>& res,vector<int> curr)
    {
        if(ind>=sz)
            {
                res.push_back(curr);
                return;
            }
            
        //discerning the frequency of curr element
        int count=1;
        for(int i=ind+1;i<sz;i++)
            if(arr[ind] == arr[i])count++;
        
        //choose vs not choose
        for(int i=0;i<=count;i++)
            {
            for(int j=0;j<i;j++)curr.push_back(arr[ind]);
                //remember we need to skip all the repeating occr.
                asu(arr,sz,ind+count,res,curr);    
           
            for(int j=0;j<i;j++)curr.pop_back();
            }
    }
    
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        //classic choose vs not choose, just that here we've got
        //couple of more options as well
        sort(arr.begin(),arr.end());
        vector<vector<int>> res;
        vector<int> curr;
        asu(arr,n,0,res,curr);
        sort(res.begin(),res.end());
        return res;
    }
};

//BitMasking solution:

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int k = nums.size();
        vector<vector<int>> res;
        
        for(int i=0;i<(1<<k);i++)
        {
            int n = i;
            vector<int> tmp;
            int j = 0;
            while(n)
            {
                if(n&1)tmp.push_back(nums[j]);
                j++;
                n>>=1;
            }
            res.push_back(tmp);
        }
        return res;
    }
};