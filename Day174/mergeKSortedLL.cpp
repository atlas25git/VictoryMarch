class Solution{
    
    Node* SortedMerge(Node* a,Node* b)
    {
        Node* result = NULL;
        if(a==NULL)return(b);
        else if(b==NULL)return(a);
        
        if(a->data <= b->data)
        {
            result = a;
            result->next = SortedMerge(a->next,b);
            
        }
        else{
            result = b;
            result->next = SortedMerge(a,b->next);
        }
        return result;
    }
    
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
           int n = K;
           int last = n-1;
        //   while(last)
        //   {
        //     //Here 2 nodes at the extreme ends are merged and
        //     //their result is stored at the beginning, this way
        //     //when i>=j, i is instantiated to 0, and j is set as last,
        //     //process continues till last becomes 0, i.e, only one combined
        //     //list exists.
        //       int i=0,j=last;
        //       while(i<j)
        //       {
        //           arr[i] = SortedMerge(arr[i],arr[j]);
        //           i++,j--;
        //           if(i>=j)
        //             last=j;
        //       }
        //   }
            
            vector<Node*> rem(arr,arr+K);
            
            while(rem.size()>1)
            {
                Node* a = rem.back();
                rem.pop_back();
                Node* b = rem.back();
                rem.pop_back();
                
                rem.push_back(SortedMerge(a,b));
            }
           return rem[0];
    }
};
