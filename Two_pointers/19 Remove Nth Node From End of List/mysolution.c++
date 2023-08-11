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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* cur = dummy;
        ListNode* re_node;
        ListNode* pre = dummy;
        int count = 0;

        while(cur)
        {
            if(count-n == 0)
            {
                pre = dummy;
                re_node = head;
            }
            else if(count-n > 0)
            {
                pre = pre->next;
                re_node = re_node->next;
            }
            count++;
            cur = cur->next;
        }
        pre->next = re_node->next;

        return dummy->next;
    }
};
