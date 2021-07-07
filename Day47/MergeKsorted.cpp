// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++




class Solution
{   
    
    struct Triplet{
    int v,i,j;
    Triplet(int v1,int i1,int j1)
        {
            v=v1;i=i1;j=j1;
        }
};

struct comp{
    bool operator()(Triplet &t1, Triplet &t2)
    {
        return t1.v>t2.v;
    }
};
    
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> res;
        priority_queue<Triplet,vector<Triplet>,comp> pq;
        //cout<<arr.size()<<"Size"<<endl;
        for(int i=0;i<K;i++)
        {
            Triplet t(arr[i][0],i,0);
            //cout<<arr[i][0]<<":L"<<i<<endl;
            pq.push(t);
        }
        while(!pq.empty())
        {
            Triplet curr=pq.top();pq.pop();
            //if(curr.v!=0)
            res.push_back(curr.v);
            if(curr.j<K)
            {
                Triplet t(arr[curr.i][curr.j+1],curr.i,curr.j+1);
                pq.push(t);
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(N, vector<int> (N, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends