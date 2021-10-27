class Solution
{
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       string ans;
       find(str,ans,0,k);
       return ans;
    }
    
    void find(string& s, string& ans,int ind,int k)
    {
        if(ind == s.size()-1 || !k)return;
        
        char nm = s[ind];
        
        for(int i =ind+1;s[i];i++)
            nm = max(nm,s[i]);
        
        if(nm!=s[ind])k--;
        
        for(int i=ind;s[i];i++)
        {
            if(s[i] == nm)
            {   swap(s[i],s[ind]);
                ans = max(ans,s);
                find(s,ans,ind+1,k);
                swap(s[i],s[ind]);
            }
        }
        
    }
};