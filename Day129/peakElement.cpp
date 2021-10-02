class Solution {
public:
    
    int peak(vector<int>& nums,int l, int h)
    {
        static int s;
        int mid = (l+h)/2;
        if(mid>0 && mid<h)
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
                        s= mid;
      
     else{
             peak(nums,mid+1,h);
             peak(nums,l,mid);
         }
        return s;
    }
    
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)return 0;
        if(nums[0]>nums[1])return 0;
        if(nums[nums.size()-1]>nums[nums.size()-2])return nums.size()-1;
        
        return peak(nums,0,nums.size()-1);
        
    }
};