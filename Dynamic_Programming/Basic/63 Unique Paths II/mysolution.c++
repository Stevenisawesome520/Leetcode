class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        if(obstacleGrid[0][0] != 1)
            dp[0][0] = 1;

        for(int i = 1; i < m; i++)
        {
            if(obstacleGrid[i-1][0] != 1 && dp[i-1][0] && obstacleGrid[i][0] != 1)
                dp[i][0] = 1;
        }
            
        
        for(int j = 1; j < n; j++)
        {
            if(obstacleGrid[0][j-1] != 1 && dp[0][j-1] && obstacleGrid[0][j] != 1)
                dp[0][j] = 1;
        }
            

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(obstacleGrid[i-1][j] != 1)
                    dp[i][j] += dp[i-1][j];

                if(obstacleGrid[i][j-1] != 1)
                    dp[i][j] += dp[i][j-1];
            }
        }
        if(obstacleGrid[m-1][n-1] || obstacleGrid[0][0])
            return 0;
        return dp[m-1][n-1];
    }
};

//simply space conplexity

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> dp(n, 0);
        for(int i = 0; i < n && obstacleGrid[0][i] != 1; i++)
            dp[i] = 1;

        for(int i = 1; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(obstacleGrid[i][j] != 1)
                {

                    if(j != 0 && dp[j-1] && dp[j])
                    {
                        dp[j] = dp[j-1] + dp[j];
                    }
                    else if(j != 0 && dp[j-1] && !dp[j])
                    {
                        dp[j] = dp[j-1];
                    }
                }
                else
                    dp[j] = 0;

            }

        }

        return dp[n-1];
        
    }
};
