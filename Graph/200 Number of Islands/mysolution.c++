class Solution {
public:
    vector<vector<char>> record;
    void traverse(vector<vector<char>>& grid, int i, int j)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0' || record[i][j] == '0')
            return;
        
        record[i][j] = '0';
        traverse(grid, i+1, j);
        traverse(grid, i, j+1);
        traverse(grid, i-1, j);
        traverse(grid, i, j-1);

    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        record = grid;

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if((grid[i][j] - '0') && (record[i][j] - '0'))
                {
                    ans++;
                    traverse(grid, i, j);
                }
            }
        }
        return ans;
    }
};
