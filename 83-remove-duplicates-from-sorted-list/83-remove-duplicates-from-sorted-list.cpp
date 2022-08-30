/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (head == NULL) return head;
        ListNode* var = head; 
        while(var!= NULL)
        {
            while (var->next && (var->next->val == var->val))
            {
                var->next = var->next->next;
            }
            var = var->next;
        }
        return head;
    }
};