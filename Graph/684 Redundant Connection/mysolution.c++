class Solution {
public:
    vector<int> parents;
    
    int findRoot(int x)
    {
        while(parents[x-1] != -1)
        {
            x = parents[x-1];
        }
        return x;
    }
    bool makeGroup(int x, int y)
    {
        int x_root = findRoot(x);
        int y_root = findRoot(y);
        if(x_root == y_root && x_root != -1)
            return false;
        
        if((x_root == y_root && x_root == -1) || x_root != y_root)
        {
            parents[x_root-1] = y_root;
            return true;
        }

        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int len = edges.size();
        for(int i = 1; i <= len; i++)
            parents.push_back(-1);
        
        for(int i = 0; i < len; i++)
            if(!makeGroup(edges[i][0], edges[i][1]))
                return edges[i];

        return {};
    }
};
