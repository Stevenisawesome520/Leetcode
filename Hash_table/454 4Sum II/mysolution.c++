class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int len = nums1.size();
        int ret = 0;
        unordered_map<int, int> tab, tab2;

        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j < len; j++)
            {
                tab[nums1[i] + nums2[j]]++;
                tab2[nums3[i] + nums4[j]]++;
            }
        }

        unordered_map<int, int>::iterator  itr;
        for(itr = tab.begin(); itr != tab.end(); itr++)
        {
            ret += (itr->second*tab2[-(itr->first)]);
        }
        return ret;
    }
};
