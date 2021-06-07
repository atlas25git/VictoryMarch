// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        int an=a.size(),bn=b.size();
        if(an!=bn)return false;
        int ch[26]={0};
        for(char x: a)ch[int(x-97)]++;
        for(char x:b)ch[int(x-97)]--;
        for(int x:ch)if(x>0)return false;
        return true;
        
        
    }

};

// { Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
  // } Driver Code Ends