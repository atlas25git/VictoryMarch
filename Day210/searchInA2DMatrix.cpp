class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        int  i = r-1,j=0;
        while(j<c && i>-1)
        {
            int ele = matrix[i][j];
            if(ele == target)return true;
            else if(ele<target)
                j++;
            else i--;
        }            
        return false;
    }
};