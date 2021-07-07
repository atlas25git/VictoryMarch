class Solution
{
    const int MAX_CHAR=26;
    public:
    struct Key
    {
    	int freq; // store frequency of character
    	char ch;
    	bool operator<(const Key &k) const
    	{
    		return freq < k.freq;
    	}
    };
    
    //Function to rearrange the characters in a string such that 
    //no two adjacent characters are same.
    string rearrangeString(string str)
    {
    	int n = str.length();
    	int count[MAX_CHAR] = {0};
    	
    	//storing count of each character in array.
    	for (int i = 0 ; i < n ; i++) 
    		count[str[i]-'a']++;
    		
    	//using a priority queue.
    	priority_queue< Key > pq;
    	
    	for (char c = 'a' ; c <= 'z' ; c++)
    		if (count[c-'a'])
    		    //storing pair of character and its frequency in priority queue.
    			pq.push( Key { count[c-'a'], c} ); 
    			
    	str = "" ;
    	//prev is used to store previous character and its frequency.
    	Key prev {-1, '#'} ;
    	
    	while (!pq.empty())
    	{
    	    //storing the top element an popping it from priority queue.
    		Key k = pq.top();
    		pq.pop();
    		str = str + k.ch;
    		
    		//if frequency of previous character is more than 0, 
    		//we push it in priority queue.
    		if (prev.freq > 0)
    			pq.push(prev); 
    			
    		//making current character as the previous character and
            //decreasing frequency by one.
    		(k.freq)--;
    		prev = k;
    	}
    	
    	return str;
    }
};