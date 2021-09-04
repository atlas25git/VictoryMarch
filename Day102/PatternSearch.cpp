class Solution
{
    public:
    //Function to check if the given pattern exists in the given string or not.
    bool search(string pat, string txt) 
    { 
        int m = pat.size();
        int n = txt.size();
        int i=0;
        while(i<=n-m)
        {
            int j;
            for(j=0;j<m;j++)
                if(txt[i+j]!=pat[j])break;
            if(j==m)return true;
            
            else if(!j)i++;
            else i=i+j;
        }
        return false;
    }
};
