class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
                swap(nums1,nums2);
        //We'll try to find out the median without actually re arranging the elements.
        //For this we can use the following reasoning of thought:-
            //Median is defined for a data, as a marker which equally divides the elements.
            //For this given the two arrays are sorted, this is a tell sign for a binary search.
            //We need to ensure that we are able to cut the arrays with makers:
                //i -> nums1
                //j -> nums2
            //All we need to ensure is that these partitions are optimal, i.e,
            //max of left set is smaller than min of right set
            //since the arrays are sorted hence we'll only need to ascertain the cases
            //for trans arrays.
        
        //since i & j are the markers on a 0 based index, hence they tell the number of elements
        //in each of the blocks.
        // => i+j = m-i + n-j + 1(in the case of odd elements, irr answer will be same for even case as 12/2 ==                                     13/2)
        // => j = (m+n+1)/2 - i;
        int m = nums1.size(),n=nums2.size();
        int start = 0,end = m;
        //end is intialized with m not m-1, 
        //Because we need a count of total no of elements.
        //to ascertain our condn respective i and j markers
        //being on 0 indexed mark the indices of the elements of 2 sets
        //And also denote no of elements in the remaining part on 1 indexing
        // For -> {1,2,3,4,5}
        //     -> {1,2,3,4}
        //(0 + 5)/2 = 2, and now minA = 2 minB = 3; 
        while(start<=end)
        {
            int minA = start + (end-start)/2;
            int minB = (m+n+1)/2 - minA;
            
            int maxA = minA-1,maxB=minB-1;
            
            //for it being a case of median we need to ascertain
            //minA>maxB && minB>maxA
            
            if(maxA>=0 && nums1[maxA] > nums2[minB])
                end = minA - 1;
            else if(minA<m && nums1[minA] < nums2[maxB])
                start = minA + 1;
            else{
                //condn satisfied calculate median now
                int maxL,minR;
                if(minA && minB)//both have some elements
                    maxL = max(nums1[maxA],nums2[maxB]);
                else if(minA)
                    maxL = nums1[maxA];
                else if(minB)
                    maxL = nums2[maxB];
                
                //left side given the extra element
                if((m+n)&1)return maxL;
                
                if(minA<m && minB<n)
                    minR = min(nums1[minA],nums2[minB]);
                else if(minA<m)
                    minR = nums1[minA];
                else if(minB<n)
                    minR = nums2[minB];
                
                return(maxL + minR)/2.0;
            }
            
        }
        return -1;
    }
};