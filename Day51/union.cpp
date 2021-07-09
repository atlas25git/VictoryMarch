//Notes:
33

// Range-based for loops work with arrays, but not with pointers. The issue here is that arrays is actually a pointer and not an array.
// When you have a function parameter that is declared as an array, it is adjusted to a pointer type. You can see this here with the 
// parameter float arrays[3][3]: In the compiler error message you can see that the actual parameter type is a pointer to an array float (*)[3],
//  which can't be used with a ranged-based for loop.
// If you pass the array by reference instead (float (&arrays)[3][3]), it won't adjusted to a pointer in this manner and will therefore work
// with the range-based for loop.


// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        unordered_set<int> s;
        for(int i=0;i<n;i++)s.insert(a[i]);
        for(int i=0;i<m;i++)s.insert(b[i]);
        return s.size();
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends