class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        //initializing two pointers for two corners.
        int a = 0;
        int b = n - 1;
        
        //we keep moving till the a<b. 
        while (a < b) {
            if (M[a][b])
                a++;
            else
                b--;
        }
        
        //checking if a is actually a celebrity or not.
        for (int i = 0; i < n; i++)
        {
            //if any person doesn't know a or a knows any person, we return -1. 
            if ( (i != a) && (M[a][i] || !M[i][a]) )
                return -1;
        }
        //if we reach here a is celebrity so we retun a.
        return a;
    }
};