// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// class Solution
// {
//     public:
//     //Function to find two repeated elements.
//     pair<int,int> twoRepeated (int arr[], int N)
//     {
//         for(int i=0;i<N+2;i++)
//         {
//             arr[arr[i]%(N+1) - 1] += (arr[i]%(N+1))*(N+1);
//         }
//         // cout<<"arr"<<endl;
        
//         // for(int i=0;i<N+2;i++)cout<<arr[i]<<" ";
//         // cout<<endl;
        
//         int a=-1,b=-1;
//         for(int i=0;i<N+2;i++)
//         {
//             if(arr[i]/(N+1)==2*(i+1))
//             {
//                 if(a==-1)a=i+1;
//                 else b=i+1;
//             }
//         }
//         if(a>b)return make_pair(a,b);
//         else return make_pair(b,a);
//     }
// };

class Solution
{
    public:
    //Function to find two repeated elements.
    pair<int,int> twoRepeated(int a[], int n)
    {    
        pair<int , int > res;
        bool first = false;
        
        //iterating over the array elements.
        for(int i=0;i<n+2;i++)
        {
            //making the visited elements negative.
            if(a[abs(a[i])]>0)
                a[abs(a[i])]=-a[abs(a[i])];
            
            //if the number is negative, it was visited previously
            //so this would be the repeated element.
            else
            {
                //storing first and second repeated element accordingly.
                if(first == false)
                {
                    res.first = abs(a[i]);
                    first = true;
                }
                else
                {
                    res.second = abs(a[i]);
                    break;
                }
            }
        }
        //returning the result.
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
        pair<int , int>res;
        res = obj.twoRepeated(a, n);
        cout<<res.first<<" "<<res.second<<endl;
    }
    return 0;
}
  // } Driver Code Ends