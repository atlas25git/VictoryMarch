class Solution
{
    public:
    
    struct comparator{
      
      bool operator()(pair<int,int> p1,pair<int,int> p2)
      {
          if(p1.second==p2.second)
                return p1.first<p2.first;
                
            return p1.second<p2.second;
      }
        
    };
    
    //Function to return the sum of frequencies of k numbers
    //with most occurrences in an array.
    int kMostFrequent(int arr[], int n, int k) 
    { 
    	map<int,int> mp;
    	
    	for(int i=0;i<n;i++)
    	    mp[arr[i]]++;
    	
    	priority_queue<pair<int,int>,vector<pair<int,int>>,comparator> pq(mp.begin(),mp.end());
    	int ans=0;
    	while(k--)
    	{
    	    ans+=pq.top().second;
    	    pq.pop();
    	}
    	return ans;
    } 
};