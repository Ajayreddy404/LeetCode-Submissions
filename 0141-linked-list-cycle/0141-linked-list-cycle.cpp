/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL)    return false;
        ListNode* f = head;
        ListNode* s = head;
        
        while(f->next && f->next->next){
            if(f->next->next == s->next){
                return true;
            }
            f = f->next->next;
            s = s->next;
        }
        return false;
    }
};