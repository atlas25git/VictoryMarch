class Solution {
public:
    int m,n;
    vector<vector<int>> memo;
    int minDistance(string word1, string word2) {
        m=size(word1);
        n=size(word2);
        memo.resize(m+1,vector<int>(n+1,0));
        
        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
            {
                if(!i)
                    memo[i][j] = j;
                else if(!j)
                    memo[i][j] = i;
                else if(word1[i-1] == word2[j-1])
                    memo[i][j] = memo[i-1][j-1];
                else
                    memo[i][j] = 1 + min({memo[i-1][j-1],memo[i][j-1],memo[i-1][j]});
            }
        
//         //recMD(word1,word2,m,n);
//         for(auto x: memo)
//         {
//             for(auto y: x)
//                 cout<<y<<" ";
//             cout<<endl;
//         }
        
        return memo[m][n];
    }
    
    int recMD(string w1, string w2,int m,int n)
    {
        if(!m) return n;
        if(!n) return m;
        if(memo[m][n])
            return memo[m][n];
        if(w1[m-1] == w2[n-1])
            return memo[m][n] = recMD(w1,w2,m-1,n-1);
        
        else return memo[m][n] = 1 + min({
                            recMD(w1,w2,m-1,n),
                            recMD(w1,w2,m-1,n-1),
                            recMD(w1,w2,m,n-1)
                            });
    }
};