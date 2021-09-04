class Solution
{
    public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
    	unordered_map<char, int> um;
    	int minIndex = INT_MAX;
    
    	int m = str.size();
    	int n = patt.size();

    	for (int i = 0; i < m; i++)
    		if (um.find(str[i]) == um.end())
    			um[str[i]] = i;

    	for (int i = 0; i < n; i++)
        {
    		if (um.find(patt[i]) != um.end() && um[patt[i]] < minIndex)
    		{
    			minIndex = um[patt[i]];
    		}
        }
    	if (minIndex != INT_MAX)
    		return minIndex;
    	else
    		return -1;
    }
};