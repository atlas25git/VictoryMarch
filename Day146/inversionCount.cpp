#define ll long long
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    ll mc=0;
    
    void merge(ll a[],ll p, ll mid,ll q)
    {
        ll l1 = mid -p +1;
        ll l2 = q-mid;//exclusive of mid
        ll a1[l1],a2[l2];
        
        for(ll i=0;i<l1;i++)a1[i] = a[p+i];
        for(ll i=0;i<l2;i++)a2[i] = a[mid+1+i];
        
        ll i=0,j=0,k=p;
        while(i<l1 && j<l2)
        {
            if(a1[i]<=a2[j])
            {
                a[k] = a1[i];
                k++,i++;
            }
            else
            {
                a[k] = a2[j];
                j++,k++;
                mc += (l1-i);
            }
        }
        while(i<l1)
        {
            a[k++] = a1[i++];
        }
        while(j<l2)
        {
            a[k++] = a2[j++];
        }
    }
    
    void ms(long long a[],ll p,ll  q)
    {
        if(p<q)
        {
            ll mid = (p+q)/2;
            ms(a,p,mid);
            ms(a,mid+1,q);
            merge(a,p,mid,q);
        }
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        ms(arr,0,N-1);
        return mc;
        
    }

};