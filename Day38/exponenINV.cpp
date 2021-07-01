// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
 

class Solution{
    public:
    
    // X[], Y[]: input arrau
    // M, N: size of arrays X[] and Y[] respectively
    //Function to count number of pairs such that x^y is greater than y^x.
    //in general x^y > y^x if y>x
    //corner cases: 0,1,2,3,4
    //x: 0 -> 0
    //   1 -> only zeros
    //ill included in gt
    //   2 -> 3 gt ,4 eq
    //not included in smaller
    //   3 -> no of 2's
    //for 4 it'll satisy as we're only considering y>4
    // if x = 0, then count for this is 0.
    // if x = 1, then count is total no of 0s in Y[] only.
    // if x = 2, for y = 3, y = 4, the above property does not hold, and the count should be decreased
    // if x = 3, for y = 2, the count need to be increased
    
    int count(int x,int Y[],int N,int queer[])
    {
        if(x==0)return 0;
        if(x==1)return queer[0];
        int* idx = upper_bound(Y,Y+N,x);
        
        int ans = (Y+N)-idx;
        
        //since we're starting the srch oprn from x>1 therefore we'll manually
        //be adding these
        //if(x!=0 && x!=1)
        //then x^(0||1)>no of [0]s and [1]s
        ans+=(queer[0]+queer[1]);
        
        if(x==2) ans-=(queer[3]+queer[4]);
        
        //as the ones we count are the gt numerals
        if(x==3) ans+=(queer[2]);
        return ans;
        
    }
    
    long long countPairs(int X[], int Y[], int M, int N)
    {   
        int queer[5] = {0};
        for(int i=0;i<N;i++)
            if(Y[i]<5)
            queer[Y[i]]++;
       sort(Y,Y+N);
       long long tp=0;
       for(int i=0;i<M;i++)
       {
           tp += count(X[i],Y,N,queer);
       }
       return tp;
    }
};


// { Driver Code Starts.
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int M,N;
		cin>>M>>N;
		int i,a[M],b[N];
		for(i=0;i<M;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<N;i++)
		{
			cin>>b[i];
		}
		Solution ob;
		cout<<ob.countPairs(a, b, M, N)<<endl;
	}
}  // } Driver Code Ends