class Solution
{
    public:
    //Function to find nth number made of only prime digits.
    int primeDigits(int n)
    {
        n--;
        vector<int>ans({2,3,5,7});
        int i=0,j=0,dt=0,c=0,k=4;
        vector<int> a({2,3,5,7});
        
        for(int i=22;i<2300;i++)
        {
            int p = i;
            dt=0,c=0;
            while(p)
            {
                dt++;
                int r = p%10;
                p=p/10;
                for(j=0;j<4;j++)
                    {
                        if(r==a[j]){c++;break;}
                    }
            }
            if(c==dt)ans.push_back(i);
            else continue;
            
        }
        //for(auto x: ans)cout<<x<<" ";
        return ans[n];
    }
};