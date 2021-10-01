class Solution
{
    public:
    
    void fmu(string& s,int k,int ind,string& res)
    {
        if(!k || ind == s.size()-1)return;
        char maxY = s[ind];
        
        //finding out the next max
        for(int i=ind+1;s[i];i++)
            maxY = max(maxY,s[i]);
        
        //if no gr8r element in the remaining string
        //we do not reduce the swap count
        if(maxY != s[ind])k--;
        
        //k--;
        for(int i=ind;s[i];i++)
        {
            if(maxY == s[i])//first occr then second
                {
                    swap(s[i],s[ind]);
                    if(s>res)res = s;
                    
                    fmu(s,k,ind+1,res);
                    swap(s[i],s[ind]);
                }
        }
        
    }
    
    
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       //since the no of swaps have been restricted thus we'll resort to
       //backtracking
       string res;
        //we'll iterate through the string while making an exit on swap count 
        //becoming 0
        fmu(str,k,0,res);
        return res;
    }
};

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