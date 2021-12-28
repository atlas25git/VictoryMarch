/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

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
        {   //Here we are not storing sH->next coz we aren't changing it as
            //we did in the augment fn.
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