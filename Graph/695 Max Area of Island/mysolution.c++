class Solution {
public:
    int explore(vector<vector<int>>& grid, int i, int j)
    {
        if(i > grid.size() - 1 || j > grid[0].size() - 1 || i < 0 || j < 0 ||　grid[i][j] == 0)
            return 0;
        
        grid[i][j] = 0;
        return 1 + explore(grid, i, j+1) + explore(grid, i, j-1) + explore(grid, i+1, j) +  explore(grid, i-1, j);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int maxA = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j])
                    maxA = max(maxA, explore(grid, i, j));
            }
        }
        return maxA;
        
    }
};
