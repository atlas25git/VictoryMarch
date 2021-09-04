#include<bits/stdc++.h>
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        int n1=str1.size(),n2=str2.size();
        if(n1!=n2)return false;
        vector<bool> marked(256,0);
        vector<int> map(256,-1);
        
        for(int i=0;i<n1;i++)
        {
            if(map[str1[i]]==-1)//seen first time
            {
                if(marked[str2[i]])return false;
                marked[str2[i]] = true;
                map[str1[i]] = str2[i];
            }
            else if(map[str1[i]] != str2[i])return false;
        }
        return true;
        
    }
};