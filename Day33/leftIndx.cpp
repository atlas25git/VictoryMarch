int leftIndex(int sizeOfArray, int arr[], int elemntToSearch){
    
    int lo = 0, hi = sizeOfArray-1, mid = lo + ((hi-lo)/2);
    
    // looping through array using binary search
    while(lo <= hi){
        // calculate mid
        mid = lo + ((hi-lo)/2);
        
        // if element is equal to arr[mid] and arr[mid-1] < element to search
        // element is found, return true
        if(arr[mid] == elemntToSearch && (mid == 0 || arr[mid-1] < elemntToSearch )){
            return mid;
        }
        
        // if elemntToSearch > middle of current array,
        // go for higher part of array
        if(elemntToSearch > arr[mid]){
            lo = mid+1;
        }
        // if elemntToSearch < middle of current array,
        // go for lower part of array
        else
            hi = mid-1;
        
    }
    
    // if element is not there in the array, return false
    return -1;
}