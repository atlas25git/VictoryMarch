class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0,e=nums.size()-1;
        if(nums.size()==1)return nums[0];
        if(nums[0]<nums[nums.size()-1])return nums[0];
        int ans = INT_MAX;
        
        while(s<=e)
        {
            int m = s + (e-s)/2;
            
            if(m!=0 && nums[m-1]>nums[m])
                ans=min(ans,nums[m]);
            if(m!=nums.size()-1 && nums[m]>nums[m+1])
                ans = min(ans,nums[m]);
            
            if(nums[m]<nums[e])e=m-1;
            else s=m+1;
            
        }
        return ans;
    }
};