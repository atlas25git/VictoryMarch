class Solution {
public:
    string s;
    
    string longestPalindrome(string str) {
        this->s = str;
        // string ans = bruteForce(s);
        string ans = dpBased(s);
        return ans;
    }
    
    bool isPal(int start,int end)
    {
        while(start<=end)
        {
            if(s[start] != s[end])
                    return false;
            start++,end--;
        }
        return true;
    }
    
    string bruteForce(string s)
    {
        int ml = 1,start = 0;
        
        for(int i=0;i<s.size();i++)
        {
            for(int j = i;j<s.size();j++)
            {
                int strt = i,end = j;
                if(isPal(i,j))
                {   
                    int chk = ml;
                    ml = max(ml,j-i+1);
                    if(chk!=ml)start = i;
                }
            }
        }
        
        return s.substr(start,ml);
    }
    
    string dpBased(string s)
    {
        int n = s.size();
        int start = 0,ml = 1;
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        //dp[i][j] -> indicates if the substring of s from i to j is a pallindrome
        //recurrence relation dp[i][j] = dp[i+1][j-1] && s[i] == s[j];
        
        //trivial cases pallindromes of len 1 and 2
        for(int i=0;i<n;i++)dp[i][i] = 1;
        for(int i=0;i<n-1;i++)if(s[i] == s[i+1])dp[i][i+1]=1,start=i,ml=2;
        
        //taking len on 0 based index
        // for(int len = 2;len<n;len++)
        // {
        //     for(int i=0;i<n-len;i++)
        //     {
        //         if(s[i] == s[i+len] && dp[i+1][i+len-1])
        //         {
        //             dp[i][i+len] = 1;
        //             ml = len+1;
        //             start = i;
        //         }
        //     }
        // }
        //1 Based indexing
         for(int len = 3;len<=n;len++)
        {
            for(int i=0;i<=n-len;i++)
            {
                if(s[i] == s[i+len-1] && dp[i+1][i+len-1 - 1])
                {
                    dp[i][i+len-1] = 1;
                    ml = len;
                    start = i;
                }
            }
        }
        return s.substr(start,ml);
    }
};