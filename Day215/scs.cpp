class Solution {
    private:
    string s1,s2;
    vector<vector<int>> dp;
        
    public:
    string shortestCommonSupersequence(string str1, string str2) {
        //Basically the lcs problem but selection 
        //has to be made on the selection of maximum len
        
        s1 = str1,
        s2 = str2;
        str1 = "";
        dp.resize(s1.size()+1,vector<int>(s2.size()+1,0));
        recSCS(0,0);
        
        for(auto x: dp)
        {
            for(auto y:x)
                cout<<y<<" ";
            cout<<"\n";
        }
        
        int i=0,j=0;
        
        while(i<s1.size() && j<s2.size())
        {   
            cout<<i<<" "<<j<<" ";
            if(s1[i] == s2[j])
            {
                str1 += s1[i];
                i++,j++;
            }
            //here we're making a chocice as in we've  to move in the 
            //direction of maximized lcs, and while moving in the direction
            //we got to add the extra chars of the strings which don't constitute,
            //in the lcs.
            //and hence in the following state we have maximal direction on choosing i,
            //as we're doing a reversed traversal hence +1 indicates the state of exclusion.
            //and leaving j, and hence here we keep ith index at the lcs term and add
            //the non lcs term of j to the string resultant.
            else if(dp[i+1][j] < dp[i][j+1])
            {
                str1 += s2[j++];
            }
            else //if(dp[i+1][j] < dp[i][j+1])
                str1 += s1[i++];
            cout<<"alt "<<i<<" "<<j<<"\n";

        }
        
        
        while(i<s1.size())
            str1 += s1[i++];
        while(j<s2.size())
            str1 += s2[j++];
        
        return str1;
    }
    
    int recSCS(int i,int j)
    {
        if(i>=s1.size() || j>=s2.size())
            return 0;
        
        if(dp[i][j])return dp[i][j];
        
        if(s1[i] == s2[j])
            return dp[i][j] = 1+recSCS(i+1,j+1);
        
        return dp[i][j] = max(recSCS(i+1,j),recSCS(i,j+1));
    }
};

//     3 3 2 2 1 1 0 0 
//     3 3 2 2 1 1 0 0 
//     2 2 2 2 1 1 0 0 
//     1 1 1 1 1 1 0 0 
//     1 1 0 0 0 0 0 0 
//     1 1 0 0 0 0 0 0 
//     0 0 0 0 0 0 0 0 
//     0 0 0 0 0 0 0 0 

// 0 0 alt 1 0
// 1 0 alt 1 1
// 1 1 alt 2 2
// 2 2 alt 2 3
// 2 3 alt 3 4
// 3 4 alt 3 5
// 3 5 alt 4 6
// 4 6 alt 5 6
// 5 6 alt 6 6
// 6 6 alt 7 6