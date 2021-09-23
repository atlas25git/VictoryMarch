class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > m, int r, int c) 
    {
        int lt=0,rt=c-1,tp=0,dn=r-1;
        
        vector<int> res;
        while(lt<=rt && tp<=dn)
        {
            for(int i=lt;i<=rt;i++)
                res.push_back(m[tp][i]);
            tp++;
            
            for(int i=tp;i<=dn;i++)
                res.push_back(m[i][rt]);
            rt--;
            
            if(tp<=dn)
            {
                for(int i=rt;i>=lt;i--)
                    res.push_back(m[dn][i]);
                dn--;
            }
            
            if(lt<=rt)
            {
                for(int i=dn;i>=tp;i--)
                    res.push_back(m[i][lt]);
                lt++;
            }
        }
        // cout<<res.size()<<endl;
        return res;
    }
};