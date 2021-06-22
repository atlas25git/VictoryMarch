// { Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

struct eleCount 
{
    int e; // Element
    int c; // Count
};
class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) 
    {
        int count = 0;
        if (k < 2) 
        return 0;
    
        //because the elements that can appear more than n/k times
        //can atmost be k as, n/k * k =n;
        eleCount temp[k];
        for (int i = 0; i < k - 1; i++) 
            temp[i].c = 0;
    
        //iterating over the array.
        for (int i = 0; i < n; i++)
        {
            int j;
            //if arr[i] is already present in the element-count array temp[], 
            //then we increment its count.
            
            for (j = 0; j < (k - 1); j++) 
            {
                if (temp[j].e == arr[i]) {
                    temp[j].c += 1;
                    break;
                }
            }
            //if arr[i] is not present in temp[]
            if (j == k - 1)
            {
                int l;
                //if there is position available in temp[] then we place arr[i] 
                //in the first available position and set its count as 1.
                for (l = 0; l < k - 1; l++) 
                {
                    if (temp[l].c == 0) {
                        temp[l].e = arr[i];
                        temp[l].c = 1;
                        break;
                    }
                }
                //if all the position in the temp[] are filled then we
                //decrease count of every element by 1.
                //Moore's voting algorithm is used here.
                //we decrement the count of vote for every not of the same kind vote found.
                if (l == k - 1)
                    for (l = 0; l < k; l++) 
                        temp[l].c -= 1;
            }
        }
    
        //chceck step of moore's voting algorithm
        for (int i = 0; i < k - 1; i++) 
        {
            int ac = 0; 
            //calculating actual count of elements.
            for (int j = 0; j < n; j++)
                if (arr[j] == temp[i].e) 
                    ac++;
    
            //if actual count is more than n/k then we increment the answer.
            if (ac > n / k) 
                count++;
        }
        return count;
    }

};


// { Driver Code Starts.
int main() {
    int t, k;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends