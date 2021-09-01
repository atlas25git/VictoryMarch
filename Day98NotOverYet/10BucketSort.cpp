//Uniform distribution: Egalitatian distribution across all the segnents made.
//Nos evenly distributed in range from 1 to 10^8
//Floating point numbers uniformly distributed in 0.0 to 1.0
//Though cmp based techniques are an option, but we won't then be leveraging the fact
//that numbers are uniformly distributed.

//The smaller buckets are sorted using insertion sort and thus in the worst
//case if the data is non uniormly distributed then it could be entirely O(N^2)
//When using nlogn algo for bucket sorting then this worst case could be averted but, then
//again we'll use the leverage that we had using bucket sort for linear analysis.
 //k~n / O(n) algo

 void bucketSort(int arr[], int n, int k) 
{ 
    int max_val=arr[0];
    for(int i=1;i<n;i++)
        max_val=max(max_val,arr[i]);
        
    max_val++;     
    vector<int> bkt[k]; 
  
    for (int i = 0; i < n; i++) { 
        int bi = (k * arr[i])/max_val; 
        bkt[bi].push_back(arr[i]); 
    } 
  
    for (int i = 0; i < k; i++) 
        sort(bkt[i].begin(), bkt[i].end()); 
   
    int index = 0; 
    for (int i = 0; i < k; i++) 
        for (int j = 0; j < bkt[i].size(); j++) 
            arr[index++] = bkt[i][j]; 
}