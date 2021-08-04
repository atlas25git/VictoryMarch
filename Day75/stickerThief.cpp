class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        //storing sum up to current element including and 
        //excluding it in respective variables.
        int incl_curr = arr[0]; 
        int excl_curr = 0; 
        
        //storing sum up to previous element including and 
        //excluding it in respective variables.
        int incl_prev = incl_curr; 
        int excl_prev = excl_curr; 
        
        for (int i = 1; i < n; i++)
        {
            //updating sum up to current element excluding it as maximum
            //of sum upto previous element excluding and including it.
            excl_curr = max(incl_prev, excl_prev); 
            
            //updating sum up to current element including it as sum up to 
            //previous element excluding it + current element.
            incl_curr = excl_prev + arr[i]; 
            
            //updating sum upto previous element including and 
            //excluding it for next iteration.
            excl_prev = excl_curr;  
            incl_prev = incl_curr; 
        }
        
        //returning the maximum of sum up to current element  
        //including and excluding it.
        return max(excl_curr, incl_curr);
    }
};

class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        int ic = arr[0];
        int ec = 0;
        
        int ip = ic;
        int ep =0;
        
        for(int i=1;i<n;i++)
            {
                ec = max(ip,ep);
                ic= ep + arr[i];
                
                ip=ic;
                ep = ec;
            }
        return max(ec,ic);
    }
};

class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        int ic = arr[0];
        int ec = 0;
        
        int ip = max(ic,ec);
        int ep = ec;
        
        for(int i=1;i<n;i++)
        {
            ic = max(ep+arr[i],ip);
            ec = max(ip,ep);
            
            ip = ic;
            ep = ec;
        }
        
        return max(ic,ec);
    }
};