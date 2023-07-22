class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> out(temperatures.size(), 0);
        stack<int> st;
        st.push(0);
        for(int i = 1; i < temperatures.size(); i++)
        {
            if(temperatures[i] > temperatures[st.top()])
            {
                while(!st.empty() && temperatures[i] > temperatures[st.top()])
                {
                    out[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
            else
            {
                st.push(i);
            }

        }
        return out;
    }
};
