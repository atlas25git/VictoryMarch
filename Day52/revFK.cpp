// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n,k;
        cin>>n>>k;
        queue<int> q;
        while(n-->0){
            int a;
            cin>>a;
            q.push(a);
        }
        queue<int> ans=modifyQueue(q,k);
        while(!ans.empty()){
            int a=ans.front();
            ans.pop();
            cout<<a<<" ";
        }
        cout<<endl;
    }
}// } Driver Code Ends


//User function Template for C++

//Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k)
{   //if(k==q.size())return q;
    stack<int> s;
    int c=k;
    while(k)
    {
        s.push(q.front());
        q.pop();
        k--;
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
     for (int i = 0; i < q.size() - c; i++) 
        {   //cout<<"executed"<<"\n";
            q.push(q.front());
            q.pop();
        }
    return q;
}// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //We are going in iterative process, at each step
       //checking if we can reach the other +1 station;
       int start=0;//starting with 0
       int end = 1;//checking for it's immidiate neighbor
       int cp = p[start].petrol - p[start].distance;//net fuel remaining 
       
       //checking for subsequent sub stations
       //cp<0 -> indicatory that curr. starting point or some interm, is not feasible
       //start!=end -> that it is not yet completed.
       while(cp<0 || start!=end)
       {   
           //we're checking in iterative manner therefore, if we 
           //reach start+1 with cp>=0, thus we can proceed twrds
           //the end
           while(cp<0 && start!=end)
           {
               //denouncing the starting station
               cp -= p[start].petrol - p[start].distance;
               start = (start+1)%n;
               if(!start)return -1;
           }
           cp += p[end].petrol - p[end].distance;
           end = (end+1)%n;
       }
       return start;
       
    }
};



// { Driver Code Starts.

int main()// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n,k;
        cin>>n>>k;
        queue<int> q;
        while(n-->0){
            int a;
            cin>>a;
            q.push(a);
        }
        queue<int> ans=modifyQueue(q,k);
        while(!ans.empty()){
            int a=ans.front();
            ans.pop();
            cout<<a<<" ";
        }
        cout<<endl;
    }
}// } Driver Code Ends


//User function Template for C++

//Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k)
{   //if(k==q.size())return q;
    stack<int> s;
    int c=k;
    while(k)
    {
        s.push(q.front());
        q.pop();
        k--;
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
     for (int i = 0; i < q.size() - c; i++) 
        {   //cout<<"executed"<<"\n";
            q.push(q.front());
            q.pop();
        }
    return q;
}
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends