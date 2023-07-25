class Solution {
public:
    string reverseStr(string s, int k) {
        string::iterator head = s.begin();
        string::iterator tail = s.begin();
        int count = 0;
        while(tail != s.end())
        {
            count++;
            tail++;
            if(count == k)
            {
                reverse(head, tail);
                head = tail;
            }
            else if(count == 2 * k)
            {
                count = 0;
                head = tail;
            }
        }
        if(count < k)
            reverse(head, tail);
        

        return s;
    }
};
