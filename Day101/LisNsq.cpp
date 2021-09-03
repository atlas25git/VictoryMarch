int LIS( int arr[], int n )  
{  
    int lis[n]; 
   
    lis[0] = 1;    
  
  
    for (int i = 1; i < n; i++ )  
    { 
        lis[i] = 1; 
        for (int j = 0; j < i; j++ )   
            if ( arr[i] > arr[j])  
                lis[i] = max(lis[i], lis[j] + 1);  
    } 
    
    int res = lis[0];
    
    for(int i=0;i<n;i++)
    {
        res = max(lis[i], res);
    }
    
    return res;
 
}  