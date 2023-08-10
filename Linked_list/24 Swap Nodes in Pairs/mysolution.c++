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
    ListNode* swapPairs(ListNode* head) {
        if((!head) || !(head->next))
             return head;
        
        ListNode *ans = head->next;
        ListNode *temp;
        ListNode *pre = nullptr;
        while(head)
        {
            if(head->next)
            {
                temp = head->next->next;
                head->next->next = head;
                if(pre)
                    pre->next = head->next;
                head->next = temp;
                pre = head;
                head = temp;

            }
            else
                return ans;
        }
        return ans;
    }
};
