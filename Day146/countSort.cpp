class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string arr){
        char op[arr.size()];
        
        int count[256],i;
        memset(count,0,sizeof(count));
        
        for(int i=0;arr[i];i++)
            ++count[arr[i]];
        
        for(int i=1;i<256;i++)
            count[i]+=count[i-1];
        
        
        for(int i=0;arr[i];i++)
            op[count[arr[i]]-1]=arr[i],
            --count[arr[i]];
            
        for(int i=0;arr[i];i++)
            arr[i]=op[i];
        
        return arr;
    }
};
