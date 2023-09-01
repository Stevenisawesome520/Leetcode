class Solution {
public:
    int ans = 0;
    void traversal(vector<vector<int>>& grid, bool b, int i, int j)
    {
        if(i < 0 || i > grid.size()-1 || j < 0 || j > grid[0].size()-1 || grid[i][j] == 0)
            return;

        if(grid[i][j])
        {
            if(!b)
                ans++;
            grid[i][j] = 0;
            traversal(grid, b, i, j+1);
            traversal(grid, b, i, j-1);
            traversal(grid, b, i-1, j);
            traversal(grid, b, i+1, j);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();//4
        int n = grid[0].size();//4
        for(int j = 0; j < n; j++)
        {
            if(grid[0][j])
                traversal(grid, true, 0, j);
            if(grid[m-1][j])
                traversal(grid, true, m-1, j);
        }
        for(int i = 1; i < m - 1; i++)
        {
            if(grid[i][0])
                traversal(grid, true, i, 0);
            if(grid[i][n-1])
                traversal(grid, true, i, n-1);
        }

        for(int i = 1; i < m-1; i++)
        {
            for(int j = 1; j < n-1; j++)
            {
                if(grid[i][j])
                    traversal(grid, false, i, j);
            }
        }

        return ans;
    }
};
