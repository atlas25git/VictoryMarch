class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) 
{   
    //We can discern that roatations could be at 0*,90*,180*,270*
	//Hennce now calculating the respective coordinate translations
    //And we check for each element of the matrix if any such rotation holds 
    //for the entirity.
        
    vector<bool> c(4,1);
	int n=mat.size()-1;
	
    for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			//0*
            if(mat[i][j]!=target[i][j]) c[0]=false;
			//90*
            if(mat[i][j]!=target[j][n-i]) c[3]=false;
			//180*
            if(mat[i][j]!=target[n-i][n-j]) c[2]=false;
			//270*
            if(mat[i][j]!=target[n-j][i]) c[1]=false;
		}
	}
	return c[0]||c[1]||c[2]||c[3];
}
};