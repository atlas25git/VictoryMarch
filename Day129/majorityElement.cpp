class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ind = 0,c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[ind] == nums[i])c++;
            else c--;
            if(!c)c=1,ind=i;
        }
        return nums[ind];
    }
};