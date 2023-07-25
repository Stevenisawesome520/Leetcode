class Node
{
public:
    int val;
    Node* next;
    Node(int x): val(x), next(nullptr){}
};

class MyLinkedList {
public:
    int idx = -1;
    Node* head = nullptr;
    Node* tail = nullptr;
    MyLinkedList() {
    }
    int get(int index) {
        if(index < 0 || index > idx)
            return -1;
        Node *cur = head;
        int curN = 0;
        while(curN != index)
        {
            curN++;
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        Node *node = new Node(val);
        if(idx == -1)
        {
            head = node;
            tail = node;     
        }
        else
        {
            node->next = head;
            head = node;
        }
        idx++;
    }
    
    void addAtTail(int val) {
        Node *node = new Node(val);
        if(idx == -1)
        {
            head = node;
            tail = node;     
        }
        else
        {
            tail->next = node;
            tail = node;
        }
        idx++;
        
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > idx+1)
            return;
        Node *node = new Node(val);
        if(index == 0)
        {
            addAtHead(val);
        }
        else if(index == idx+1)
        {
            tail->next = node;
            tail = node;
        }
        else
        {
            Node *last = nullptr;
            Node *cur = head;
            int curN = 0;
            while(curN != index)
            {
                curN++;
                last = cur;
                cur = cur->next;
            }
            last->next = node;
            node->next = cur;

        }
        idx++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index > idx)
            return;

        if(index == 0)
        {
            Node *temp = head;
            head = head->next;
            temp->next = nullptr;
            idx--;
            return;
        }

        Node *last = nullptr;
        Node *cur = head;
        int curN = 0;
        while(curN != index)
        {
            curN++;
            last = cur;
            cur = cur->next;
        }
        if(index == idx)
        {
            tail = last;
            tail->next = nullptr;

        }
        else
        {
            last->next = cur->next;
            cur->next = nullptr;
        }

        idx--;
        return;
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
