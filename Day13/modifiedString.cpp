// { Driver Code Starts
#include<bits/stdc++.h>
#define br char xx; cin>>xx; cout<<xx<<endl;
#define lli long long int
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to find minimum number of characters which Ishaan must insert  
    //such that string doesn't have three consecutive same characters.
    int modified(string a)
    {
        int ans, same;
        ans=0;
        same=1;
        //whole idea is that for every three ch. found same
        //we add a charachter and return the total no. of them required
        //Ofc for n<3 the calculative prowess would be 0.
        
        //checking for any three consecutive same characters and if they are
        //found then we increment the count of characters to be added.
        for(int i=1;a[i];i++)
        {
            if(a[i]==a[i-1]){
                same++;
            }
            else{
                ans+=(same-1)/2;//fancy way of writing if sum=3, then count++,else 0
                same=1;
            }
        }
        ans += (same-1)/2;
        //returning the answer.
        return ans;
    }

};

int modified(string a)
    {
    //int count=0;for(int i=0;i<a.length()-2;){if(a[i]==a[i+1]&&a[i+1]==a[i+2])count++,i+=2;else i+=1;}return count;}
    
    //4 count
    int ans=0,sum=1,lt=3;
    for(int i=1;a[i];i++){
        
        if(a[i]==a[i-1])sum++;
        else ans += (sum-1)/(lt-1),sum=1;
    }
    ans+=(sum-1)/(lt-1);
    return ans;
    }

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    string a;
    while(t--){
        cin>>a;
        Solution obj;
        cout<<obj.modified(a)<<endl;
    }
    return 0;
}
  // } Driver Code Ends