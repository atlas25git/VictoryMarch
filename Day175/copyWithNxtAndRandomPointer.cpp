class Solution {
public:
    Node* copyRandomList(Node* head) {
        //augmenting the list 
        if(!head)return head;
        Node* sH = head;
        
        while(sH)
        {
            Node* tmp = sH->next;
            sH->next = new Node(sH->val);
            sH->next->next = tmp;
            sH = tmp;
        }
        //augmenting random pointer
        sH = head;
        
        while(sH)
        {
            sH->next->random = sH->random?sH->random->next:NULL;
            sH = sH->next->next;
        }
        //seperating the two lists
        Node* ans = head->next;
        sH = head;
        Node* nxtOG;
        
        while(sH)
        { 
            nxtOG = sH->next->next;
            sH->next->next = nxtOG?nxtOG->next:NULL;
            sH->next = nxtOG;
            sH = nxtOG;
        }
        
        return ans;
    }
};