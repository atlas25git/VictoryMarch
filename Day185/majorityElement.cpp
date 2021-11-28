class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int size)
    {
        
        int ind = 0,c=1;
        for(int i=1;i<size;i++)
        {
            if(arr[i] == arr[ind])c++;
            else c--;
            if(!c)c=1,ind=i;
        }
        c=0;
        for(int x=0;x<size;x++)if(arr[x]==arr[ind])c++;
        if(c>size/2)
            return arr[ind];
        return -1;
    }
};