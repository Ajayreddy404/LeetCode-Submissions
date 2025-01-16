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
        ListNode* f = head->next;
        ListNode* s = head;
        
        while(f && f->next){
            if(f == s){
                return true;
            }
            f = f->next->next;
            s = s->next;
        }
        return false;
    }
};