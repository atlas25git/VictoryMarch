//TimSort -> insertion + merge
//Intro Sort -> quick + heap + insertion sort

// Comparison based sorting:
// 1) Bubble sort and Insertion sort – 
//      Average and worst case time complexity: n^2 
//      Best case time complexity: n when array is already sorted. 
//      Worst case: when the array is reverse sorted. 
 
// 2) Selection sort – 
//      Best, average and worst case time complexity: n^2 which is independent of distribution of data. 
 
// 3) Merge sort – 
//      Best, average and worst case time complexity: nlogn which is independent of distribution of data. 
 
// 4) Heap sort – 
//      Best, average and worst case time complexity: nlogn which is independent of distribution of data. 
 
// 5) Quick sort – 
//      It is a divide and conquer approach with recurrence relation: 
//          T(n) = T(k) + T(n-k-1) + cn
//      Worst case: when the array is sorted or reverse sorted, the partition algorithm divides the
//      array in two subarrays with 0 and n-1 elements. Therefore, 
//          T(n) = T(0) + T(n-1) + cn
//      Solving this we get, T(n) = O(n^2)
//      Best case and Average case: On an average, the partition algorithm divides the array in two subarrays with equal size. Therefore, 
//          T(n) = 2T(n/2) + cn
//      Solving this we get, T(n) = O(nlogn)

// Non-comparison based sorting – 

// Radix sort – 
// Best, average and worst case time complexity: nk where k is the maximum number of digits in elements of array. 
 
// Count sort – 
// Best, average and worst case time complexity: n+k where k is the size of count array. 
 
// Bucket sort – 
// Best and average time complexity: n+k where k is the number of buckets. 
// Worst case time complexity: n^2 if all elements belong to same bucket. 

// Analysis
// When the array is almost sorted, insertion sort can be preferred.
// When order of input is not known, merge sort is preferred as it 
//      has worst case time complexity of nlogn and it is stable as well.
// When the array is sorted, insertion and bubble sort gives complexity 
//       of n but quick sort gives complexity of n^2.

