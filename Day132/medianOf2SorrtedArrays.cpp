class Solution
{
    public:
    //Function to find the median of the two arrays when they get merged.
    int findMedian(int arr[], int n, int brr[], int m)
    {
        //Basically the idea here is that we iterate the bigger array
        //based on the smaller one's flow, here we divise the two points
        //namely minA, minB which at any instance divide the array elements into 2
        //now the nos preceeding them are called maxA, maxB
        //while start<=end we iterate to find the callibration of minA, minB
        //such that all the elements left of minA and minB are smaller than them
        
        
        // The basic idea being that we need to return the median of 2 adjacents of the 
        // cut made to divide the array
        
        int start = 0,end = n,i,j,median;
        
        while(start<=end)
        {
            i = start + (end-start)/2;
            j = (n+m+1)/2-i;
            
            int minA = i,minB=j,maxA=i-1,maxB=j-1;
            
            //now following codn has to be ascertained till both the pointers have
            //valid partitions, 
            //minA >= maxB
            //minB >= maxA
            
            //minA < maxB
            //minA needs to be shifted right
            if(minA < n && minB > 0 && arr[minA] < brr[maxB])
                start = i+1;
            
            //minB < maxA
            //minB needs to be shifted left(in the decreasing dirn)
            else if(minB <m && minA>0 && arr[maxA] > brr[minB])
                end = i-1;
            
            //condn ascertained storing first part of median now
            else
            {
                if(!minA)
                    //maxA doesn't exist
                    median = brr[maxB];
                if(!minB)
                    //maxB doesn't exist
                    median = arr[maxA];
                    //both exist hence the larger of the two
                else median = max(arr[maxA],brr[maxB]);
                break;
            }
        }
        
        //deciding based on nature of set, i.e., odd/even
        if((n+m)&1)return (double)median;
        //partition validitiy on the right side
        if(j>m-1)
            //j doesn't exist
            return (median + arr[i])/2.0;
        if(i>n-1)
            //i doesn't exist
            return (median + brr[j])/2.0;
        return (median + min(arr[i],brr[j]))/2.0;
    }
};