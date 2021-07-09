// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
map<int,int> mp; // mp hold 1 to those number which consists of only 1, 2, 3 as digits only 


 // } Driver Code Ends
//User function template for C++

//Function to find all the numbers with only 1,2 and 3 in their digits.
void findAll() {
    
    int num=1,num2;
    vector<int> a;int j=1;
    a.push_back(j);
    a.push_back(j+1);
    a.push_back(j+2);
    mp[1]=1;
    mp[2]=1;
    mp[3]=1;
    j=0;
    while(num<=10e6)
    {
        num2=a[j++];
        if(num2*10 + 1 <10e6)
        {
            a.push_back(num2*10+1);
            mp[num2*10+1]=1;
        }
        if(num2*10 + 2 <10e6)
        {
            a.push_back(num2*10+1);
            mp[num2*10+2]=1;
        }
        if(num2*10 + 3 <10e6)
        {
            a.push_back(num2*10+1);
            mp[num2*10+3]=1;
        }
        
        num2=num2*10 + 3;
        if(num2<=10e6)
        {
            a.push_back(num2);
            mp[num2]=1;
        }

        num=num2;

    }
    
}

// { Driver Code Starts.


int main()
{   
    findAll(); // find all such numbers whose digits are from set {1,2,3} from 1 to 1000000
    int t;
    cin>>t; 
    
    while(t--)
    {
        int n, flag=0;
        cin>>n; 
        
        int arr[n] ;
        
        for(int i=0;i<n;i++) // insert n elements
            cin >> arr[i]; 
        
        sort(arr,arr+n); // sort them
        
        for(int i = 0 ; i < n ; ++ i ) {
            if(mp[arr[i]]) { // if arr[i] is already there in the map then it satisfied else not 
                cout << arr[i] << " " ;
                flag=1;
            }
        }
        
        if(!flag)
            cout << "-1"; 
            
        cout<<endl;
    }
return 0;
}  // } Driver Code Ends