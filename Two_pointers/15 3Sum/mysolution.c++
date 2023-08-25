// hash table
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int> > ret;
        unordered_map<int, int> tab;
        int len = nums.size();
        for(int i = 0; i < len; i++)
        {
            tab[nums[i]] = i;
        }

        for(int i = 0; i < len-2; i++)
        {
            for(int j = i + 1; j < len-1; j++)
            {
                if(tab.find(-nums[i]-nums[j]) != tab.end() && tab[-nums[i]-nums[j]] > i && tab[-nums[i]-nums[j]] > j)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(-nums[i]-nums[j]);
                    ret.push_back(temp);

                    i = tab[nums[i]];
                    j = tab[nums[j]];
                }
            }
        }
        return ret;       
    }
};

// two pointers
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int> > ret;

        int len = nums.size();

        for(int i = 0; i < len - 2; i++)
        {
            int left = i + 1, right = len - 1;
            while(left < right)
            {
                if(nums[i] + nums[left] + nums[right] == 0)
                {
                    vector<int> tempV = {nums[i], nums[left], nums[right]};
                    ret.push_back(tempV);
                    int temp = nums[left];
                    while(left < right && nums[++left] == temp)
                        continue;
                }
                else if(nums[i] + nums[left] + nums[right] > 0)
                {
                    int temp = nums[right];
                    while(left < right && nums[--right] == temp)
                        continue;
                }
                else
                {
                    int temp = nums[left];
                    while(left < right && nums[++left] == temp)
                        continue;
                }
            }
            int temp = nums[i];
            while(nums[i+1] == temp && i < len - 2)
                i++;
                
        }

        return ret;
    
    }
};
