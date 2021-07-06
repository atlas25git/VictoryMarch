#include<bits/stdc++.h>
using namespace std;

int arr[1000000];

//using set to count smaller elements on right side.
set<int> s;

//Function to count maximum number of distinct smaller 
//elements on right side of any array element.
int countSmallerRight(int n)
{
    int countSmaller = 0;
    
    //iterating over the array elements.
    for(int i = n-1; i >= 0; i--)
    {
        //inserting the array element in set.
        s.insert(arr[i]);
        
        //it stores the location of current element thus we calculte 
        //it's distance
        auto it = s.lower_bound(arr[i]);
        //cout<<*it<<"it"<<endl;
        
        //finding the distance between above found element and the
        //beginning of the set using distance function.
        if(distance(s.begin(), it) > countSmaller)
            countSmaller = distance(s.begin(), it);
    }
    //returning the list.
    return countSmaller;
}

//main function
int main(){
    
    int t;
    cin >> t;
    while(t--)
    {
        s.clear();
        
        //taking inputs from user.
        int n;
        cin >> n;
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        //printing the result.
        cout << countSmallerRight(n) << endl;
    }
    return 0;
}

int cs(int n)
{
    int cs=0;
    for(int i=n-1;i>=0;i--)
    {
        s.insert(arr[i]);
        auto it = s.lower_bound(arr[i]);
        int dis = distance(s.begin(),it);
        if(dis>cs)
            cs=dis;
    }
    return cs;
}