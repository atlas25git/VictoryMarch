//1. Linear time algorithm but for the cases where number of elements are
//   small but are in the range 0 to K-1 then O(n+k).
//   Theta(n+k) space complexity.
//2. Only useful when k is linear in terms of n, as n,2n,n/2 etc.
//3. Used as a sub routine in radix sort.

///For stability:
//We maintain frequency acc to occr of elements.
//Now we add up the previous frequencies for any i int the index.
//Generating a cumulative freq array.
//Now we start traversing array from last pos, making a lookup call for it's
//frequency and then place the element at rank and reduce the freq.
//Thus the order is maintained.

void countSort(int arr[], int n, int k) 
{ 
    int count[k];
    for(int i=0;i<k;i++)
        count[i]=0;
    for(int i=0;i<n;i++)
        count[arr[i]]++;
        
    for(int i=1;i<k;i++)
        count[i]=count[i-1]+count[i];
    
    int output[n];
    //starting from n-1 to maintain stability. As the one occurring latter
    //should be as such, object clause.
    //As we can discern that the number of elements will be equal to the frequency as mentioned, hence
    //every time we see one to fix it while traversing we choose the last such possible index for that position,
    //and hence reduce the freq by 1.
    //In this way the relative order is maintained.
    for(int i=n-1;i>=0;i--){
        output[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
    for(int i=0;i<n;i++)
        arr[i]=output[i];
    
} 