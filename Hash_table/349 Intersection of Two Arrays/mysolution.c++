class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> tab;
        for(int i = 0; i < nums1.size(); i++)
        {
            tab[nums1[i]] = 1;
        }
        for(int i = 0; i < nums2.size(); i++)
        {
            if(tab[nums2[i]])
            {
                tab[nums2[i]] = 0;
                ans.push_back(nums2[i]);
            }
        }

        return ans;
    }
};
