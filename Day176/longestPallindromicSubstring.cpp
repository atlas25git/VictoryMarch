class Solution {
public:
    
    
    string longestPalindrome(string s) {
        
        return dpBased(s);
            //bruteForce(s);
    }
    
    string bruteForce(string& str)
    {
        int ml = 1,start=0;
        
        //Generating all the substrings 
        //starting with i = 1
        //and j varying over the bound 1.....j->n
        //similarly 2....j->n
        //for each we calculate the middle point i.e j-i+1, total elements
        //and then divided by 2, we check the substring for a pallindromic sequence
        
        for(int i=0;i<str.size();i++){
            for(int j=i;j<str.size();j++)
            {
                int flag = 1;
                for(int k=0;k<(j-i+1)/2;k++)
                    if(str[i+k] != str[j-k])
                            flag = 0;
                
                if(flag && (j-i+1) > ml)
                    start = i,
                    ml = j - i + 1;
            }
        }
        
        return str.substr(start,ml);
    }
    
    string dpBased(string s)
    {
        //p[i,j] -> substring from i to j is a pallindrome yes then 1 else 0
        //p[i,j] = (p[i+1,j-1] && s[i] == s[j])
        //                      marks dependence on prev state
        //Base cases:
        //p[i,i] -> true
        //p[i,i+1] = si == si+1;
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        int start = 0,ml=1;
        
        for(int i=0;i<n;i++)dp[i][i] = 1;
        for(int i=0;i<n-1;i++)
        {
            if(s[i] == s[i+1])
                    dp[i][i+1] = 1,
                    start = i,
                    ml  = 2;
        }
        
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<n-k+1;i++)
            {
                int endInd = i+k-1;
                if(dp[i+1][endInd-1] && s[i] == s[endInd])
                {
                    dp[i][endInd] = 1;
                    if(k>ml)
                        ml = k,
                        start = i;
                }
            }
        }
        return s.substr(start,ml);
    }
};