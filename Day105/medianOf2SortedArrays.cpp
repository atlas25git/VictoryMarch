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
        if(j==m)
            //j doesn't exist
            return (median + arr[i])/2.0;
        if(i==n)
            //i doesn't exist
            return (median + brr[j])/2.0;
        return (median + min(arr[i],brr[j]))/2.0;
    }
};


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
                    median = brr[maxB];
                if(!minB)
                    median = arr[maxA];
                else median = max(arr[maxA],brr[maxB]);
                break;
            }
        }
        
        //deciding based on nature of set, i.e., odd/even
        if((n+m)&1)return (double)median;
        //partition validitiy on the right side
        if(j==m)return (median + arr[i])/2.0;
        if(i==n)return (median + brr[j])/2.0;
        return (median + min(arr[i],brr[j]))/2.0;
    }
};

class Solution
{
    public:
    //Function to find the median of the two arrays when they get merged.
    int findMedian(int arr[], int n, int brr[], int m)
    {
        int start = 0,end = n;
        int i,j,median;
        
        while(start<=end)
        {
            //median contestant in 1st arr
            i = start + (end-start)/2;
            j = (n+m+1)/2-i;
            int minA = i,maxA = i-1;
            int minB = j,maxB = j-1;
            
            //Now following condn is to be ensured
            //minA >= maxB
            //minB >= maxA
            
            //minA < maxB
            //minA needs to be increased
            if(minA<n && minB>0 && brr[maxB] > arr[minA])
                start = i+1;
            //minB < maxA
            else if(minB<m && minA>0 && brr[minB] < arr[maxA])
                end = i-1;
            
            else{
                if(!i)
                    median = brr[maxB];
                if(!j)
                    median = arr[maxA];
                else median = max(arr[maxA],brr[maxB]);
                break;
            }
        }
        if((n+m)&1)return double(median);
        if(i==n)return (median+brr[j])/2.0;
        if(j==m)return (median+arr[i])/2.0;
        
        return (median+min(arr[i],brr[j]))/2.0;
    }
};

class Solution
{
    public:
    //Function to find the median of the two arrays when they get merged.
    int findMedian(int arr[], int n, int brr[], int m)
    {
        int start = 0,end=n;
        int i,j,median;
        
        while(start<=end)
        {
            i=(start+end)/2;
            j=(n+m+1)/2 - i;
            
            if(j<m && i>0 &&  brr[j]<arr[i-1])
                //reduce
                end = i-1;
            else if(j>0 && i<n && brr[j-1]>arr[i])
                start = i+1;
            
            else{
                if(!i)
                    median = brr[j-1];
                if(!j)
                    median = arr[i-1];
                else median = max(arr[i-1],brr[j-1]);
                break;
            }
        }
        if((n+m)&1)return (double)median;
        if(i==n)return (median + brr[j])/2.0;
        if(j==m)return (median + arr[i])/2.0;
        
        return (median + min(arr[i],brr[j]))/2.0;
    }
};