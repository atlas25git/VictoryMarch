class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())nums1.swap(nums2);
        int m = size(nums1), n = size(nums2);
        int start = 0,end=m;
        
        while(start<=end)
        {
            int minA = start + (end-start)/2;
            int minB = (n+m+1)/2 - minA;
            
            int maxA = minA-1,maxB=minB-1;
            
            if(minA<m && nums1[minA]<nums2[maxB])
                    start = minA + 1;
            else if(minA>0 && nums1[maxA]>nums2[minB])
                    end = minA -1;
            else
            {   
                //meidan would be maxL,minR/2 or maxL if it's odd
                int maxL,minR;
                if(minA && minB)
                    maxL = max(nums1[maxA],nums2[maxB]);
                else if(minA)
                    maxL = nums1[maxA];
                else if(minB)
                    maxL = nums2[maxB];
                
                if((n+m)&1)
                    return maxL;
                
                if(minA<m && minB<n)
                    minR = min(nums1[minA],nums2[minB]);
                else if(minA<m)
                    minR = nums1[minA];
                else
                    minR = nums2[minB];
                
                return (maxL + minR)/2.0;                
            }
        }
        return -1;
    }
};