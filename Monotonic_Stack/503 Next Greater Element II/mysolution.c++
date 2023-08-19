class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        vector<int> ret(len, -1000000001);
        stack<int> st;
        st.push(nums[len-1]);

        for(int i = len - 2; i >= 0; i--)
        {
            if(nums[i] >= st.top())
            {
                while(!st.empty() && nums[i] >= st.top())
                {
                    st.pop();
                }
                if(!st.empty())
                {
                    ret[i] = st.top();
                }
                st.push(nums[i]);
            }
            else if(nums[i] < st.top())
            {
                ret[i] = st.top();
                st.push(nums[i]);
            }
        }

        for(int i = len - 1; i >=0 ; i--)
        {
            if(ret[i] == -1000000001)
            {
                while(!st.empty() && nums[i] >= st.top())
                {
                    st.pop();
                }
                if(!st.empty())
                {
                    ret[i] = st.top();
                }
                else
                {
                    ret[i] = -1;
                }
                st.push(nums[i]);
            }
        }
        return ret;
    }
};
