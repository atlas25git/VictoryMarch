class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        //Brute Force: O(n^3)
        
//         auto valid = [&nums](int i,int j,int k)->bool
//         {
//             return (nums[i] + nums[j]> nums[k]
//                    && nums[i] + nums[k]> nums[j]
//                    && nums[k] + nums[j]> nums[i]);  
//         };
//         int count = 0;
//         for(int i=0;i<nums.size();i++)
//             for(int j=i+1;j<nums.size();j++)
//                 for(int k=j+1;k<nums.size();k++)
//                     if(valid(i,j,k))
//                         count++;
        
//         return count;
        
        //O(n^2)
        int count = 0;
        sort(nums.begin(),nums.end());
        int i = 0;
        i = upper_bound(nums.begin(),nums.end(),0) - nums.begin();
        for(;i<nums.size();i++)
        {
            int k = i+2;
            //We can skip the explored values of k as the once checked before
            //would already be complying, and since the relative dis is measured in counting
            //triplets hence we can resume from the last explored index of k.
            for(int j=i+1;j<nums.size()-1;j++)
            {
                // cout<<" "<<i<<" "<<j<<" "<<k<<" ";
                while(k<nums.size() && nums[i] + nums[j] > nums[k])k++;
                count += k-1-j;
                // cout<<k<<" "<<count<<"\n";
            }
            cout<<"---\n";
        }
        return count;
    }
};

 0 1 2 2 0
 0 2 2 3 0
 0 3 2 4 0
 0 4 2 5 0
 0 5 2 6 0
 0 6 2 8 1
 0 7 2 8 1
 0 8 2 9 1
---
 1 2 3 3 1
 1 3 3 6 3
 1 4 3 8 6
 1 5 3 8 8
 1 6 3 9 10
 1 7 3 9 11
 1 8 3 9 11
---
 2 3 4 8 15
 2 4 4 9 19
 2 5 4 9 22
 2 6 4 9 24
 2 7 4 9 25
 2 8 4 9 25
---
 3 4 5 9 29
 3 5 5 9 32
 3 6 5 9 34
 3 7 5 9 35
 3 8 5 10 36
---
 4 5 6 9 39
 4 6 6 9 41
 4 7 6 9 42
 4 8 6 10 43
---
 5 6 7 10 46
 5 7 7 10 48
 5 8 7 10 49
---
 6 7 8 10 51
 6 8 8 10 52
---
 7 8 9 10 53