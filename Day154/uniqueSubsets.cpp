class Solution
{   
    vector<vector<int>> ans;
    public:
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        sort(arr.begin(),arr.end());
        asu(arr,n,0,vector<int>());
        sort(ans.begin(),ans.end());
        return ans;
    }
    
    void asu(vector<int>& arr,int sz,int i,vector<int> a)
    {
        if(i>=sz)
        {
            ans.push_back(a);
            a.clear();
            return;
        }
        
        int c = 1;
        for(int j=i+1;j<sz;j++)
            if(arr[i] == arr[j])c++;
        // asu(arr,sz,i+1,a);
        for(int j=0;j<=c;j++)
            {
                for(int k=0;k<j;k++)
                    
                    a.push_back(arr[i]);
                    
                    asu(arr,sz,i+c,a);
                
                for(int k=0;k<j;k++)
                    a.pop_back();
            }
    }
};