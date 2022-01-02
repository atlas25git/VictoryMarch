class Solution {
public:
    int m,n;
    vector<vector<int>> dp;
    vector<vector<int>> dp1;
    vector<vector<int>> dp2;
    
    int longestCommonSubsequence(string t1, string t2) {
        m=size(t1);
        n=size(t2);
        dp.resize(m+1,vector<int>(n+1,0));
        dp1.resize(m+1,vector<int>(n+1,0));
        dp2.resize(m+1,vector<int>(n+1,0));

        lcsRecStart(t1,t2,0,0);
        // lcsRecLast(t1,t2,m,n);
        
        printMat(dp1,"start");
        // printMat(dp,"last");
        
        printLcs("start",t1,t2);
        // printLcs("end",t1,t2);
        // bottomUp(t1,t2);
        // printLcs("start",t1,t2);
        // printMat(dp1,"BottomUp");
        return dp1[0][0];
        
    }
    
    void bottomUp(string t1, string t2)
    {
        //nullity
        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
            {
                if(!i || !j)
                    dp2[i][j] = 0;
                else if(t1[i-1] == t2[j-1])
                    dp2[i][j] = 1 + dp2[i-1][j-1];
                else dp2[i][j] = max(dp2[i-1][j],dp2[i][j-1]);
            }
    }
    
    void printLcs(string name,string t1,string t2)
    {
        //the dichotomy between the 2 methods could be attributed
        //to the definition of the states as listed when iterating from bottom
        //i-1,j-1 indicate the consideration of that particular index
        //whereas when starting from 0 0 indicates the exclusion of ith index 
        //thereby consideration of j
        
        if(name == "start"){
            
            //both ways the printing of lcs string could be done, only thing
            //that needs be taken care is about the definition of states.
            //When we've called the fn passing args 0,0 as in recStart.
            //Here the final len will be  stored 0,0 and we've since filled the
            //matrix starting from the end, hence i-1, indicates (i-1)th char in 
            //consideration, whereas when doing the same from top, i+1 corresponds to
            //ith char being left and j been taken in consideration.
            
            // stringstream ss;
            // int i=0,j=0;
            // while(i<m && j<n)
            // {
            //     if(t1[i] == t2[j]){
            //         ss<<t1[i];
            //         i++,j++;
            //     }
						//     leaving j'th term is giving the larger and, hence max selected.
            //     else if(dp1[i+1][j] < dp1[i][j+1])
            //     {
            //         ss<<t1[i];
            //         i++;
            //     }
            //     else if(dp1[i+1][j] > dp1[i][j+1])
            //     {
            //         ss<<t2[j];
            //         j++;
            //     }else i++,j++;    
            // }
            //     cout<<ss.str()<<endl;
            
            stringstream ss;
            int i=m,j=n;
            while(i>0 && j>0)
            {
                if(t1[i-1] == t2[j-1]){
                    ss<<t1[i-1];
                    i--,j--;
                }
                else if(dp1[i-1][j] < dp1[i][j-1])
                {
                    ss<<t2[j-1];
                    j--;
                }
                else if(dp1[i-1][j] > dp1[i][j-1])
                {
                    ss<<t1[i-1];
                    i--;
                }else i--,j--;    
            }
                cout<<ss.str()<<endl;
            
            
        }else if(name == "end")
        {
            stringstream ss;
            int i=m,j=n;
            while(i>0 && j>0)
            {   
                //cout<<i<<" "<<j<<endl;
                if(t1[i-1] == t2[j-1]){
                    ss<<t1[i-1];
                    i--,j--;
                }
                //i considered since we make min choice
                else if(dp[i-1][j] < dp1[i][j-1])
                {
                    ss<<t1[i];
                    i--;
                }
                else if(dp[i-1][j] > dp1[i][j-1])
                {
                    ss<<t2[j];
                    j--;
                }
             else i--,j--;
                // cout<<i<<" "<<j<<" "<<ss.str()<<endl;
            }
                cout<<ss.str()<<endl;
        }
    
        else
        {
            stringstream ss;
            int i=1,j=1;
            
            while(i<=m && j<=n)
            {   cout<<i<<" "<<j<<endl;
                if(t1[i-1] == t2[j-1]){
                    ss<<t1[i-1];
                    i++,j++;
                }
                else if(dp2[i-1][j] > dp2[i][j-1])
                {
                    ss<<t2[j-1];
                    j++;
                }
                else if(dp2[i-1][j] < dp2[i][j-1])
                {
                    ss<<t1[i-1];
                    i++;
                }
             else i++,j++;
                cout<<i<<" "<<j<<" "<<ss.str()<<endl;
            }
                cout<<ss.str()<<endl;
        }
    }
    
    void printMat(vector<vector<int>>&dp, string name)
    {
        cout<<name<<endl;
        for(auto x: dp)
        {
            for(auto y:x)
                cout<<y<<" ";
            cout<<endl;
        }
    }
    
    int lcsRecStart(string t1,string t2,int i,int j)
    {
        if(i>=m || j>=n)return 0;
        if(dp1[i][j]!=0)return dp1[i][j];
        
        if(t1[i] == t2[j])
            return dp1[i][j] = 1 + lcsRecStart(t1,t2,i+1,j+1);
        else 
            return dp1[i][j] = max(lcsRecStart(t1,t2,i,j+1),lcsRecStart(t1,t2,i+1,j));
    }
    
    int lcsRecLast(string t1, string t2, int m, int n)
    {
        if(m==0 || n==0)return 0;
        if(dp[m][n] != 0) return dp[m][n];
        
        if(t1[m-1] == t2[n-1])
            return dp[m][n] =  1+ lcsRecLast(t1,t2,m-1,n-1);
        else 
            return dp[m][n] = max(lcsRecLast(t1,t2,m-1,n),lcsRecLast(t1,t2,m,n-1));
    }
};