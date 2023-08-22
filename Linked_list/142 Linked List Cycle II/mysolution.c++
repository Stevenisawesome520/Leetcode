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
        if(!head || !head->next) return nullptr;
        ListNode *walker2 = head;
        head = head->next;
        ListNode *fast = head->next;

        while(head && fast)
        {
            
            if(head == fast)
            {
                while(walker2 != head)
                {
                    walker2 = walker2->next;
                    head = head->next;
                }
                return head;
            }
            head = head->next;
            if(fast->next)
                fast = fast->next->next;
            else
                fast = nullptr;
            

        }
        return nullptr;
    }
};
