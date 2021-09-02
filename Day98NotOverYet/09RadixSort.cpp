//1. Linear time algorithm when the data is in a limited range.
// Theta(n+b) && Stable as it uses stable counting sort.
// Where b is the base, if we increase base then time complexity will reduce
// but required space to store the elements on bases would also inc, thus a trade off
// is observed here.
//2. Better than counting sort, as it becomes O(n^2) when k is quadratic.
//3. But this remains linear even for the larger ranges.

void countingSort(int arr[], int n, int exp) 
{ 
    int output[n];  
    int count[10] = { 0 }; 
    for (int i = 0; i < n; i++) 
        count[(arr[i] / exp) % 10]++; 
  
    for (int i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    for (int i = n - 1; i >= 0; i--) { 
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
        count[(arr[i] / exp) % 10]--; 
    } 
  
    for (int i = 0; i < n; i++) 
        arr[i] = output[i]; 
}  
 
void radixsort(int arr[], int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
  
    for (int exp = 1; mx / exp > 0; exp *= 10) 
        countingSort(arr, n, exp); 
} 