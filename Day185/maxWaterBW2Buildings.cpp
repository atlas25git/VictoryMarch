class Solution
{
    public:
    //Function to return the maximum water that can be stored.
    int maxWater(int ht[], int n) 
    { 
        int ans = INT_MIN;
        int i=0,j=n-1;
        while(i<=j)
        {
            if(ht[i] > ht[j])
                ans = max(ans,ht[j]*(j-i-1)),
                j--;
            else if(ht[i] < ht[j])
                ans = max(ans,ht[i]*(j-i-1)),
                i++;
            else
                ans = max(ans,(j-i-1)*ht[j]),
                i++,j--;
        }
        return ans;
    } 
};