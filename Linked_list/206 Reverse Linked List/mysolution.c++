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

//Recursive
class Solution {
public:
    ListNode* ans;
    void goThrough(ListNode* pre, ListNode* cur)
    {
        if(!cur)
        {
            ans = pre;
            return;
        }
        goThrough(cur, cur->next);
        cur->next = pre;
    }
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;

        goThrough(head, head->next);
        head->next = nullptr;
        return ans;
    }
};

//Iterative
class Solution {
public:
    
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;

        ListNode* temp;
        ListNode* pre = head;
        temp = head->next;
        pre->next = nullptr;
        head = temp;
        while(head)
        {
            temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
            
        }
        return pre;
    }
};
