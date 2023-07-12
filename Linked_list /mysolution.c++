class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *last = nullptr;
        ListNode *current = head;
        while(current != nullptr)
        {
            if(current->val == val)
            {
                if(current == head)
                {
                    head = current->next;
                    delete current;
                    current = head;
                }
                else
                {
                    last->next = current->next;
                    delete current;
                    current = last->next;
                }
            }
            else
            {
                last = current;
                current = current->next;
            }
        }
        return head;
    }
};
