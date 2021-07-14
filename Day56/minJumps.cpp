class Solution
{
    public:
    //Function to find minimum number of jumps to reach the end of the array.
    int minimumJumps(int arr[], int n)
    {
        //base cases
        if(n<=1)            
            return 0;
        if(arr[0] == 0)    
            return -1;
        
        //using maxrange to store the index till which we can jump and 
        //steps to store the number of indexes we can travel in one jump.  
        int maxrange = arr[0]; 
        int steps = arr[0];   
        int jumps = 1;    
        
        for(int i = 1; i<n; ++i)
        {
            //if we reach the end of array, we return the number of jumps.
            if(i == n-1) 
            return jumps; 
            
            //updating maxrange by comparing current maxrange and current value.
            maxrange = max(maxrange, i+arr[i]);
            //reducing steps each time we are moving forward.
            steps--;                            
            
            //if steps become 0, we have to increase the number of jumps.
            if(steps == 0)
            {                     
                ++jumps;  
                
                //if maxrange is less than or equal to i, we can't
                //move further so we return -1.
                if(i>= maxrange) 
                return -1;    
                
                //updating the steps.
                steps = maxrange - i;   
            }
         }
         return -1; 
    }
};

//july 14th
class Solution
{
    public:
    //Function to find minimum number of jumps to reach the end of the array.
    int minimumJumps(int arr[], int n){
        
        if(n<=1)return 0;
        if(!arr[0])return -1;
        
        int maxRange = arr[0];
        int steps = arr[0];
        int jumps = 1;
        for(int i=1;i<n;i++)
        {
            if(i==n-1)return jumps;
            
            maxRange = max(maxRange,i+arr[i]);
            steps--;
            //just so that we know when all the possibilites have been explore
            //and we've settled for the best option        
            if(!steps)
            {
                jumps++;
                //the case where there is no such option in the proximity of
                //our i'th element so as to reach to current i', as former has the
                //greedy solution of them all.
                if(i>=maxRange)
                    return -1;
                    
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
        
        //base case
        if(n<=1)return 0;
        if(!arr[0])return -1;
        
        int mR = arr[0];
        int st = arr[0];
        int j=1;
        for(int i=1;i<n;i++)
        {
            //base case
            if(i==n-1)return j;
            
            mR = max(mR,arr[i]+i);
            //i and st are complementary to each other, hence
            //i denotes the step position max reachable from starting point.
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