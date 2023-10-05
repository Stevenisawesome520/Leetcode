class Solution {
public:

    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& ocean, vector<vector<bool>>& haveBeen)
    {   
        ocean[i][j] = true;
        haveBeen[i][j] = true;
        if(i != 0 && heights[i-1][j] >= heights[i][j] && !haveBeen[i-1][j])
            dfs(heights, i-1, j, ocean, haveBeen);
        if(i != heights.size()-1 && heights[i+1][j] >= heights[i][j] && !haveBeen[i+1][j])
            dfs(heights, i+1, j, ocean, haveBeen);
        
        if(j != heights[0].size()-1 && heights[i][j+1] >= heights[i][j] && !haveBeen[i][j+1])
            dfs(heights, i, j+1, ocean, haveBeen);
        if(j != 0 && heights[i][j-1] >= heights[i][j] && !haveBeen[i][j-1])
            dfs(heights, i, j-1, ocean, haveBeen);
        
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));
        
        for(int j = 0; j < n; j++)
        {
            vector<vector<bool>> haveBeen(m, vector<bool>(n, false));
            dfs(heights, 0, j, pac, haveBeen);
        }
            
        for(int i = 1; i < m; i++)
        {
            vector<vector<bool>> haveBeen(m, vector<bool>(n, false));
            dfs(heights, i, 0, pac, haveBeen);
        }
            
        for(int j = 0; j < n; j++)
        {
            vector<vector<bool>> haveBeen(m, vector<bool>(n, false));
            dfs(heights, m-1, j, atl, haveBeen);
        }
        for(int i = 0; i < m-1; i++)
        {
            vector<vector<bool>> haveBeen(m, vector<bool>(n, false));
            dfs(heights, i, n-1, atl, haveBeen);
        }
            

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(pac[i][j] && atl[i][j])
                    ans.push_back(vector<int>{i,j});
            
        
        return ans;
    }
};
