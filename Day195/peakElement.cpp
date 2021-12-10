class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1)return 0;
        int start = 0,end = nums.size()-1;
        
        while(start <= end)
        {
            int m = start + (end-start)/2;
            if(nums[m] >= nums[max(0,m-1)] && nums[m] >=nums[min((int)nums.size()-1,m+1)])
                return m;
            else if(nums[m] >=  nums[max(0,m-1)])
                start = m+1;
            else end = m-1; 
            
        }
        return -1;
    }
};