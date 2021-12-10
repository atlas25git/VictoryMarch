    int firstMissingPositive(vector<int>& nums)
    {   
        
        //the idea here is to first segragate the array from all the negative elements
        //and then use the remainig indices to use as markers for positive elements present
        //if any mark remains unmarked thus telling the missing no.
        //if none then the size+1 is the missing number
        
        int offset = partition(nums.begin(),nums.end(),[](int s){return s<=0;}) - nums.begin();
        int n = nums.size();
        for(int i=offset;i<n;i++)
            if(abs(nums[i])<=n-offset)
                if(nums[abs(nums[i])-1 + offset] > 0)
                    nums[abs(nums[i])-1 + offset] *= -1;
        
        for(int i=offset;i<n;i++)
            if(nums[i]>0)
                    return i-offset+1;
        
        return n-offset+1;
    }
