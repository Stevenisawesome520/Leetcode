class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        vector<int> ans(len1, -1);

        unordered_map<int, int> m;
        for(int i = 0; i < len1; i++)
            m[nums1[i]] = i;

        stack<int> st;
        st.push(10001);

        for(int i = nums2.size()-1; i >=0; i--)
        {
            if((m[nums2[i]] == 0 && nums2[i] == nums1[0]) || m[nums2[i]] != 0)
            {
                while(st.top() < nums2[i])
                    st.pop();
                if(st.top() == 10001)
                    ans[m[nums2[i]]] = -1;
                else
                    ans[m[nums2[i]]] = st.top();
                st.push(nums2[i]);
            }
            else
            {
                while(st.top() < nums2[i])
                    st.pop();
                st.push(nums2[i]);
            }
        }
        return ans;
    }
};
