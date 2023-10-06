class Solution {
public:
    int maxA = 0;
    vector<vector<int>> maxI;
    void dfs(vector<vector<int>>& grid, int i, int j, int number)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return;
        
        if(grid[i][j] == 1)
        {
            grid[i][j] = number;
            maxA++;
            dfs(grid, i + 1, j, number);
            dfs(grid, i - 1, j, number);
            dfs(grid, i, j + 1, number);
            dfs(grid, i, j - 1, number);
        }
    }
    void mark(vector<vector<int>>& grid, int i, int j, int number)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return;
        
        if(grid[i][j] == number)
        {
            maxI[i][j] = maxA;
            if(i+1 < grid.size() &&  maxI[i+1][j] != maxA) mark(grid, i + 1, j, number);
            if(i-1 >= 0 && maxI[i-1][j] != maxA) mark(grid, i - 1, j, number);
            if(j+1 < grid[0].size() && maxI[i][j+1] != maxA) mark(grid, i, j + 1, number);
            if(j-1 >= 0 && maxI[i][j-1] != maxA) mark(grid, i, j - 1, number);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 1;
        for(int i = 0; i < m; i++)
            maxI.push_back(vector<int>(n, 0));
        int number = -1;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    maxA = 0;
                    dfs(grid, i, j, number);
                    mark(grid, i, j, number);
                    ans = max(ans, maxA);
                    number--;
                }  
            }
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 0)
                {
                    unordered_map<int, bool> umap;
                    int addNum = 1;
                    if(i-1 >= 0 && !umap[grid[i-1][j]] && maxI[i-1][j])
                    {
                        addNum +=  maxI[i-1][j];
                        umap[grid[i-1][j]] = true;
                    }
                    if(i+1 < m && !umap[grid[i+1][j]] && maxI[i+1][j])
                    {
                        addNum +=  maxI[i+1][j];
                        umap[grid[i+1][j]] = true;
                    }
                    if(j-1 >= 0 && !umap[grid[i][j-1]] && maxI[i][j-1])
                    {
                        addNum +=  maxI[i][j-1];
                        umap[grid[i][j-1]] = true;
                    }
                    if(j+1 < n && !umap[grid[i][j+1]] && maxI[i][j+1])
                    {
                        addNum +=  maxI[i][j+1];
                        umap[grid[i][j+1]] = true;
                    }

                    ans = max(ans, addNum);
                }
            }
        }

        return ans;
        

        
    }
};
