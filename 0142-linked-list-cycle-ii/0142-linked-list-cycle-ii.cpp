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
    ListNode *detectCycle(ListNode *head) {
        if(!head)    return NULL;

        ListNode* f = head;
        ListNode* s = head;

        bool ans = false;
        while(f->next && f->next->next){
            f = f->next->next;
            s = s->next;
            if(f == s){
                ans = true;
                break;
            }
            // cout<<s->val<<" "<<f->val<<endl;
        }
        // cout<<s->val<<endl;
        if(!ans)    return NULL;
        
        // return head;
        f = head;

        while(f!=s){
            f = f->next;
            s = s->next;
        }
        return f;
    }
};