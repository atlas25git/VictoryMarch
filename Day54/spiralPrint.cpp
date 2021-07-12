// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> ans;
        int top=0, left=0,right=c-1,bottom=r-1;
        
        while(top<=bottom && left<=right)
        {
            for(int i=left;i<=right;i++)
                ans.push_back(matrix[top][i]);
            top++;
            
            for(int i=top;i<=bottom;i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;
            //adding checks here as to ensure the change that has happened doesn't affect segment array
            if(top<=bottom)
                {
                    for(int i=right;i>=left;i--)
                            ans.push_back(matrix[bottom][i]);
                    bottom--;
                            
                }
            if(right>=left)
            {
                for(int i=bottom;i>=top;i--)
                    ans.push_back(matrix[i][left]);
                    
                    left++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends