class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for(int i = 1; i*i <= n; i++)
            squares.push_back(i*i);
        
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < squares.size(); i++)
            for(int j = squares[i]; j < n + 1; j++)
                dp[j] = min(dp[j], 1 + dp[j - squares[i]]);

        return dp[n];
    }
};
