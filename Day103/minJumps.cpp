class Solution
{
    public:
    //Function to find minimum number of jumps to reach the end of the array.
    int minimumJumps(int arr[], int n){
        
        //sanitation check
        if(n<=1)return 0;
        if(!arr[0]) return -1;
        
        //default case as we will start from first cell
        int maxRange = arr[0];
        int steps = arr[0];
        int j = 1;
        
        for(int i=1;i<n;i++)
        {
            if(i==n-1)return j;
            //in the forseeable range updating the max reachable
            //position by utilising 1 jump
            maxRange = max(maxRange,arr[i]+i);
            steps--;//checks if the avl domain has been checked completely
            if(!steps)
            {
                if(maxRange<=i)return -1;
                j++;//jump made
                steps = maxRange - i; 
            }
        }
        
        return -1;
        
    }
};


class Solution
{
    public:
    //Function to find minimum number of jumps to reach the end of the array.
    int minimumJumps(int arr[], int n){
        
        //sanitation check
        if(n<=1)return 0;
        if(!arr[0])return -1;
        int mR = arr[0];
        int st = arr[0];
        int j=1;
        for(int i=1;i<n;i++)
        {
            if(i==n-1)return j;
            mR = max(mR,arr[i]+i);
            st--;
            if(!st)
            {
                j++;
                if(mR<=i)return -1;
                st = mR-i;
            }
        }
        return -1;
    }
};