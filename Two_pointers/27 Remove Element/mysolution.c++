class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size() - 1;
        int k = 0;
        while(i <= j)
        {
            if(nums[i] == val)
            {
                k++;
                while(nums[j] == val && i != j)
                {
                    j--;
                    k++;
                }
                swap(nums[i], nums[j]);
                j--;
            }
            i++;
        }
        return nums.size()-k;
    }
};
