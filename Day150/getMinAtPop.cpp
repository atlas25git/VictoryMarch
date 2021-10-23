// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

stack<int> _push(int arr[],int n);

void _getMinAtPop(stack<int>s);

 // } Driver Code Ends
//User function Template for C++

int min1;
//Function to push all the elements into the stack.
stack<int> _push(int arr[],int n)
{
   stack <int>s;
    
    //iterating over the array elements and pushing them into the stack.
    for(int i=0;i<n;i++)
    {   
        if(s.empty()){
            min1=arr[i];
            s.push(arr[i]);
        }
        
        else if(arr[i]<min1)
        {   
            //this commputation is done in order to store
            //the minimum value to fallback on in the case that
            //the present one is removed,
            //since it's an eqn in 2 var we use s.top and min for the same,
            //meanwhile min contains min element latest and the s.top() at
            //corressponding pos holds 2*arr[i]-theOldMin
            s.push(2*arr[i]-min1);
            //cout<<i<<"__"<<2*arr[i]-min1<<endl;
            min1 = arr[i];
        }
        else{
            s.push(arr[i]);
        }
    }
    return s;
}

//Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int>s)
{   //cout<<"s.top "<<s.top()<<endl;
    while(!s.empty())
    {
    int t=s.top();
    s.pop();
    //check for inequality is ascertained as: 2x - y < x, given y>x
    if(t<=min1)
    {
        int res = min1;
        min1 = 2*min1 -t;
        cout<<res<<" ";
    }else cout<<min1<<" ";
    }
    // cout<<"end";
}
// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    stack<int>mys=_push(arr,n);
	    _getMinAtPop(mys);
	    
	    cout<<endl;
	    
	}
	return 0;
}

  // } Driver Code Ends