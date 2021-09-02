// Cycle Sort
// 1. O(N^2) worst case.
// 2. Min memory writes.
// 3. Inplace and Not stable.
// 4. Generally used in n questions like find min swaps.

// Algorithm:
// For an element we count the others smaller than it, and fix it's position in the traversal.
// For the element in question we fix it at it's exact position and then begin with the element,
// which was originally at this new position. In this way diff cycles are formed and hence fixed.

// a. Since we are traversing the array from 0, thus 0 to cs-1 will be sorted, and in the other half
//    elements may or may not be sorted.
// b. Last element needs not be considered, as if it were the part of some cycle, it'd be implicity fixed
//    or else it's the greatest of all, hnce iteration on cycle length only till n-2 inclusive.

void cycleSortDistinct(int arr[], int n)
{
    for(int cs=0;cs<n-1;cs++)
        {
            int itm = arr[cs];
            int pos = cs;
            for(int i=cs+1;i<n;i++)
                if(arr[i]<itm)pos++;
            swap(itm,arr[pos]);
            while(pos!=cs)
            {   
                //re initalizing pos to cs,
                //leveraging the fact that elements till cs-1 are sorted.
                //itm holds the element that was at this position
                
                pos = cs;
                for(int cs+1;i<n;i++)
                    if(arr[i]<itm)pos++;
                    swap(itm,arr[pos]);
            }
        }
}