class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        vector<char> veca,vecA;
        
        for(int i=0;i<n;i++)
		{
			int(str[i])<97?
			vecA.push_back(str[i]):
			veca.push_back(str[i]);
		}
        
        sort(veca.begin(),veca.end());
        sort(vecA.begin(),vecA.end());
        //cout<<veca.size()+vecA.size()<<endl;
        
       int vcA=0,vca=0;
		string answer="";
		
		//iterating over the given string.
		for(int i=0;i<n;i++)
		{
			int(str[i])<97?
			answer+=vecA[vcA++]:
			answer+=veca[vca++];
		}
		//returning the result.
		return answer;
    }
};