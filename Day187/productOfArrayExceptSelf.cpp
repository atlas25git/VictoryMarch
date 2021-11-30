class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long ans=1;
        int f=0;
        for(auto x: nums)
        {   
           if(x!=0) 
            ans*=x;
            else f++;
        }
        if(f == nums.size())ans=0;
        if(f == 1)
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 0)nums[i]=ans;
            else nums[i]=0;
        }
        else if(f>1)
        {
            for(int i=0;i<nums.size();i++)
            {
              nums[i]=0;
            }
        }
        else
            for(int i=0;i<nums.size();i++)nums[i]=ans/nums[i];
        
        return nums;
    }
};