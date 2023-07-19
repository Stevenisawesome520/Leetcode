//1
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;

        // dp[i]中的i表示背包内总和
        // 题目中说：每个数组中的元素不会超过 100，数组的大小不会超过 200
        // 总和不会大于20000，背包最大只需要其中一半，所以10001大小就可以了
        vector<int> dp(10001, 0);
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        // 也可以使用库函数一步求和
        // int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        int target = sum / 2;

        // 开始 01背包
        for(int i = 0; i < nums.size(); i++) {
            for(int j = target; j >= nums[i]; j--) { // 每一个元素一定是不可重复放入，所以从大到小遍历
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        // 集合中的元素正好可以凑成总和target
        if (dp[target] == target) return true;
        return false;
    }
};


//2
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int MAX_NUM = 100;
        const int MAX_ARRAY_SIZE = 200;
        bitset<MAX_NUM * MAX_ARRAY_SIZE / 2 + 1> bits(1);
        int sum = 0;
        for (auto n : nums) {
            sum += n;
            bits |= bits << n;
        }
        return !(sum % 2) && bits[sum / 2];
    }
};

num = 5
0 -> 5 (set 5's bit, since we can achieve sum 5.)
Now we can achieve 0 and 5 with [ ] and [ 5 ]. So by the union of both, we have 000000100001

num = 2
0->2
5->7
We can achieve 0,2,5,7 from [5,2] ==> [ ], [5], [2], [5,2]
After union our bitset is 000010100101

num = 4
0->4
2->6
5->9
7->11
We can achieve 0,2,4,5,6,7,11 from [5,2] ==> [ ], [5], [2], [4], [5,2], [2,4], [5,4], [5,2,4]
After union our bitset is 101011110101
