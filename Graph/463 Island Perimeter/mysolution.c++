class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j)
    {
        grid[i][j] = -1;
        int peri = 0;
        if(i != 0 && grid[i-1][j] == 1)
            peri += dfs(grid, i-1, j);
        else if(i == 0 || grid[i-1][j] == 0)
            peri++;
        
        if(i != grid.size()-1 && grid[i+1][j] == 1)
            peri += dfs(grid, i+1, j);
        else if(i == grid.size()-1 || grid[i+1][j] == 0)
            peri++;
        
        if(j != 0 && grid[i][j-1] == 1)
            peri += dfs(grid, i, j-1);
        else if(j == 0 || grid[i][j-1] == 0)
            peri++;
        
        if(j != grid[0].size()-1 && grid[i][j+1] == 1)
            peri += dfs(grid, i, j+1);
        else if(j == grid[0].size()-1 || grid[i][j+1] == 0)
            peri++;
        
        return peri;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j])
                    return dfs(grid, i, j);
        return 0;
    }
};
