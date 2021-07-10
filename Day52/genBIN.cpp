// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
	queue<string> q;
	vector<string> res;
	q.push("1");
	//N coz there'd be frst N no. whose bin rep we got to produce
	while(N--)
	{
	    string curr = q.front();
	    q.pop();
	    res.push_back(curr);
	    string prev = curr;
	    //order is imp as it is this fashion that binary no rep follows
	    //growth
	    q.push(curr.append("0"));
	    q.push(prev.append("1"));
	}
	return res;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends