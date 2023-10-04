class Solution {
public:

    void flip(vector<vector<char>>& board, int i, int j)
    {
        if(i >= board.size() || j >= board[0].size() || i < 0 || j < 0 ||　board[i][j] != 'O')
            return;

        board[i][j] = '*';
        flip(board, i, j+1);
        flip(board, i, j-1);
        flip(board, i + 1, j);
        flip(board, i - 1, j);

    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for(int j = 0; j < n; j++)
            if(board[0][j] == 'O')
                flip(board, 0, j);
        for(int j = 0; j < n; j++)
            if(board[m-1][j] == 'O')
                flip(board, m-1, j);
        for(int i = 1; i < m; i++)
            if(board[i][0] == 'O')
                flip(board, i, 0);
        for(int i = 1; i < m; i++)
            if(board[i][n-1] == 'O')
                flip(board, i, n-1);
        
        for(int i = 1; i < m - 1; i++)
            for(int j = 1; j < n - 1; j++)
                if(board[i][j] == 'O')
                    board[i][j] = 'X';

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(board[i][j] == '*')
                    board[i][j] = 'O';
    }
};
