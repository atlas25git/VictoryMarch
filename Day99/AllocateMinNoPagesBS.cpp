#define ll long long
class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) 
    {
        ll sum =0;
        
        if(n<m)return -1;//in all other cases there will be a ways such that 
                        //every student is allocated one book
        for(int i=0;i<n;i++)sum+=arr[i];
        ll s = 0;
        ll e = sum;
        ll m1;
        ll ans = INT_MAX;
        
        while(s<=e)
        {
            m1 = s+ (e-s)/2;
            
            if(isP(m1,n,m,arr))
            {
                ans = min(ans,m1);
                e = m1-1;
            }
            else
            {
                s = m1+1;
            }
        }
        return ans;
    }
    
    bool isP(ll maxMin,int n,int stud,int arr[])
    {
        int str = 1;
        int cs= 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>maxMin)return false;
            //greedy approach
            if(cs + arr[i] <= maxMin)
            {
                cs +=arr[i];
            }
            else
            {
                str++;
                cs = arr[i];
                if(str>stud)return false;
            }
        }
        return true;
    }
    
};