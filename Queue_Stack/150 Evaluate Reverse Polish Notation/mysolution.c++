class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> out;
        for(int i = 0; i< tokens.size(); i++)
        {
            if(tokens[i] == "+")
            {
                int temp = stoi(out.top());
                out.pop();
                temp += stoi(out.top());
                out.pop();
                out.push(to_string(temp));
            }
            else if(tokens[i] == "*")
            {
                int temp = stoi(out.top());
                out.pop();
                temp *= stoi(out.top());
                out.pop();
                out.push(to_string(temp));
            }
            else if(tokens[i] == "-")
            {
                int temp = stoi(out.top());
                out.pop();
                int temp2 = stoi(out.top());
                out.pop();
                temp2 -= temp;
                out.push(to_string(temp2));
            }
            else if(tokens[i] == "/")
            {
                int temp = stoi(out.top());
                out.pop();
                int temp2 = stoi(out.top());
                out.pop();
                temp2 /= temp;
                out.push(to_string(temp2));
            }
            else
            {
                out.push(tokens[i]);
            }
                            
        }
        return stoi(out.top());
    }
};
