class Solution {
public:
    bool isPalindrome(ListNode* head) {
        string s;
        while(head)
            s+=head->val,head = head->next;
        
        int i=0,j=s.size()-1;
        while(i<=j)
        {
            if(s[i] != s[j])
                return false;
            i++,j--;
        }
        return true;
    }
};