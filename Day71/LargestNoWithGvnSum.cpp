class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
    string largestNumber(int n, int sum)
    {
        //edge cases:
        if(sum>9*n)return "-1";
        if(!sum)
        {
            if(n==1)return "0";
            else
            {
                string r;
                while(n--)
                r+="0";
                return r;
            }
            
        }
        
        //simply picking the largest value that is 9til the sum>9
        string ans;
        for(int i=0;i<n;i++)
        {
            if(sum>9)ans+="9",sum-=9;
            
            else {
                ans+=to_string(sum);
                sum=0;
            }
        }
        return ans;
    }
};

class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
    string largestNumber(int n, int sum)
    {
        if(sum==0)
            {
                if(n==1)
                    return "0";
                    else {
                        string r;
                        while(n--)
                            r+="0";
                        return r;
                    }
            }
        if(sum>9*n)return "-1";
        string res;
        
        for(int i=0;i<n;i++)
        {
            if(sum>=9)
            res+="9",
            sum-=9;
            else {
                res+=to_string(sum);
                sum=0;
            }
        }
        return res;
    }
};