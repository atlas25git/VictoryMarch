class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        Node* slow=head,*fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        if(slow != fast)return;
        //Corner case:
        if(slow == head)
        {
            while(slow->next!=head)
                slow = slow->next;
            slow->next = NULL;
            return;
        }
        
        slow = head;
        
        //Proof:
        // Dis travelled by fp = 2*sp
        // ------------->------fmp--\
        //      m       |  k         \
                        ---------------
        //Loop len = x, before meeting at fmp
        //both would have travelled m dis before entering the loop,
        //then k+(someMultipleOf)x
        // 2*(m + k + x*i) = (m + k + x*j)
        // (m+k) = x*(j-i);
        // since i and j are integers hence m+k is a multiple of loop len: x
        //Now when our sp will start from head and move m steps to reach loop start
        //our fp will start from k dis away from loop start, and as we know
        //m+k is multiple of x, hence for m+k steps it'd be back at its curr pos.
        //And for just m steps it'd be k steps behind its curr pos, which
        //happend to be the loop start.
        while(slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
        return;
    }
};