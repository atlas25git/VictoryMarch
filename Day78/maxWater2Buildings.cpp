class Solution
{
    public:
    //Function to return the maximum water that can be stored.
    int maxWater(int ht[], int n) 
    { 
        //BAsic 2 pointer approach, here we start from both the ends
        //calculate maximum possible value for any given gr8r ht
        //and we take the max of sum
        
        int ans = INT_MIN;
        int  i=0,j=n-1;
        while(i<=j)
        {
            if(ht[i]<ht[j])
                ans = max(ans,(ht[i])*(j-i-1)),
                i++;
            else if(ht[i] > ht[j])
                ans = max(ans,(ht[j])*(j-i-1)),
                j--;
            else 
                ans = max(ans,ht[i]*(j-i-1)),
                i++,j--;
        }
        
        return ans;
    } 
};


class Solution
{
    public:
    //Function to return the maximum water that can be stored.
    int maxWater(int height[], int n) 
    {   
        int max1=0;
        int i=0,j=n-1;
        while(i<j)
        {
            if(height[i]<height[j])
            {
                max1 = max(max1,(j-i-1)*height[i]);
                i++;
            }
            
            else if(height[j]<height[i])
            {
                max1 = max(max1,(j-i-1)*height[j]);
                j--;
            }
            else{
                max1=max(max1,(j-i-1)*height[i]);
                i++,j--;
            }
        }
    
        return max1;
    } 
};