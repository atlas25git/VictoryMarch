// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    
    void fm(string str,int k,string& max,int count)
    {
        if(!k)return;
        
        char maxm = str[count];
        for(int i=count+1;str[i];i++)
            if(maxm<str[i])
                maxm=str[i];
                
        if(maxm != str[count])
            k--;
            
        for(int i=count;str[i];i++)
        {
            if(str[i]==maxm)
            {
            swap(str[i],str[count]);
                if(str.compare(max)>0)
                    max=str;
            fm(str,k,max,count+1);
            swap(str[i],str[count]);
            }}
    }
    
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
        string max=str;
        fm(str,k,max,0);
        return max;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends