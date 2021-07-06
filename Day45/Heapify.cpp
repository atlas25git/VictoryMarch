//check if min(par,left,right) == par
//if not swap par with min, and recursively proceed.
 
 void minHeapify(int i)
 {
     int lt = left(i),rt=right(i);
     int smallest = o;
     if(lt<size && arr[lt]<arr[i])
        smallest = lt;
    if(rt<size && arr[rt]<arr[smallest])
        smallest=rt;
    
    if(smallest!=i)
    {
        swap(arr[i],arr[smallest]);
        minHeapify(smallest);
    }
 }