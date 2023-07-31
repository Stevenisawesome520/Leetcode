// Dp
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 2);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++)
            dp[i] = dp[i-1] + dp[i-2];

        return dp[n];
    }
};

//Recursive Time Limit Exceeded
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};


//best
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
       int pre1 = 1, pre2 = 2;
       for(int i = 3; i <= n; i++)
       {
           int temp = pre1;
           pre1 = pre2;
           pre2 = temp + pre2;
       }
       return pre2;
    }
};
