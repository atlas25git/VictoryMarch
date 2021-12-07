class Solution
{   string s,ans;
    int n;
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string s, int k)
    {   n= s.size();
       this->s = s;
       find(0,k);
       return ans;
    }
    
    void find(int ind, int k)
    {
        if(ind == n-1 || !k)return;
        char cr = s[ind];
        
        //finding next max
        for(int i=ind;i<n;i++)
            cr = max(cr,s[i]);
        if(cr!=s[ind])
            k--;
        for(int i=ind;i<n;i++)
        {
            if(s[i] == cr)
                {
                    swap(s[i],s[ind]);
                    ans = max(ans,s);
                    find(ind+1,k);
                    swap(s[i],s[ind]);
                }
        }
        return;
    }
};
