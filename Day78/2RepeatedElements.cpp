// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int N) {
        // Your code here
        vector<int> res;
        //since given that array contains elements in the range 1 to N
        //thus we utilize the fact and mark indices as array element's occr
        //if we encounter an element in O(n) traversal, whose index has been marked
        //neg thus we've the repeating element
        bool first = false;
        for(int i=0;i<N+2;i++)
        {
            if(arr[abs(arr[i])]>0)//first occr
                arr[abs(arr[i])] *= -1;
            else
            {
                if(!first)
                {
                    res.push_back(abs(arr[i]));
                    first = true;
                }
                else
                {
                    res.push_back(abs(arr[i]));
                }
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        int a[n+2];
        
        for(int i=0;i<n+2;i++)
            cin>>a[i];
        
        Solution obj;
        vector<int> res;
        res = obj.twoRepeated(a, n);
        cout<<res[0]<<" "<<res[1]<<endl;
    }
    return 0;
}
  // } Driver Code Ends


  // C++ code for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the duplicate
// value in the given array arr[]
void findDuplicate(int arr[])
{

	// Initialise variables
	int tortoise = arr[0];
	int hare = arr[0];

	// Loop till we find the
	// duplicate element
	while (1) {

		tortoise = arr[tortoise];

		// Hare moves with twice
		// the speed of tortoise
		hare = arr[arr[hare]];
		if (tortoise == hare)
			break;
	}

	tortoise = arr[0];

	// Loop to get start point
	// of the cycle as start
	// point will be the duplicate
	// element
	while (tortoise != hare) {
		tortoise = arr[tortoise];
		hare = arr[hare];
	}

	// Print the duplicate element
	cout << tortoise;
}

// Driver Code
int main()
{
	// Given array
	int arr[] = { 2, 6, 4, 1, 3, 1, 5 };

	// Function Call
	findDuplicate(arr);

	return 0;
}


//Won't give ys the distance