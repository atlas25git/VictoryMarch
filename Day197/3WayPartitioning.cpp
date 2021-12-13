class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition1(vector<int>& ar,int a, int b)
    {
        int l=0,r=ar.size()-1;
        int itr = 0;
        while(itr<=r)
        {
            if(ar[itr] < a)//element for first window
                swap(ar[itr++],ar[l++]);
            else if(ar[itr]>b)
                //itr not incremented as we want to check the element for 'a'
                swap(ar[itr],ar[r--]);
            else itr++;
        }
    }
    void threeWayPartition(vector<int>& ar,int a, int b)
    {
       int l=0,r=ar.size()-1,itr=0;
       while(itr<=r)
       {
           if(ar[itr]<a)swap(ar[itr++],ar[l++]);
           else if(ar[itr]>b)swap(ar[itr],ar[r--]);
           else itr++;
       }
    }
};