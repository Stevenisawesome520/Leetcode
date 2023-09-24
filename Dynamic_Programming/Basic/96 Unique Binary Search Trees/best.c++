//dp
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; i++) 
            for(int j = 1; j <= i; j++)
                dp[i] += dp[j-1] * dp[i-j];
        return dp[n];
    }
};

//Catalan Numbers
class Solution {
public:
    long ncr(int n, int r) {
        long ans = 1;
        for(int i = 0; i < r; i++) {
            ans *= n-i;
            ans /= i+1;
        }
        return ans;   
    }
    int numTrees(int n) {
        return ncr(2*n, n) / (n + 1);
    }
};
