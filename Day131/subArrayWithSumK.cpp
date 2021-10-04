class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, int s)
    {
        int cs = 0;
        vector<int> res;
        int start=0,end=0;
        
        for(int i=0;i<n;i++)
        {
            cs += arr[i];
            if(cs>=s)
            {   end = i;
                
                while(cs>s && start <= end)
                    {
                        cs -= arr[start++];
                    }
                
                
                if(cs == s)
                {   //1 based indexing
                    res.push_back(start+1);
                    res.push_back(end+1);
                    break;            
                }  
            }
        }
        
        if(!res.size())res.push_back(-1);
        return res;
        
    }
    
};