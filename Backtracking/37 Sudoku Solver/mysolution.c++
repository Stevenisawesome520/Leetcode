class Solution {
public:


    bool isValid(vector<vector<char>>& board, int r, int c, char k)
    {
        for(int j = 0; j < 9; j++)
            if(board[r][j] == k)
                return false;
        
        for(int i = 0; i < 9; i++)
            if(board[i][c] == k )
                return false;


        for(int i = (r/3) * 3; i < (r/3) * 3 + 3; i++)
        {
            for(int j = (c/3) * 3; j < (c/3) * 3 + 3; j++)
            {
                if(board[i][j] == k)
                    return false;
            }
        }

        return true;
        
    }

bool final = false;

    void solve(vector<vector<char>>& board, int i, int j)
    {
        for(char k = '1'; k <= '9'; k++)
        {
            if(isValid(board, i, j, k) && board[i][j] == '.')
            {
                board[i][j] = k;

                int r2 = -1, c2 = -1;
                for(int r = 0; r < 9; r++)
                {
                    for(int c = 0; c < 9; c++)
                    {
                        if(board[r][c] == '.')
                        {
                            r2 = r;
                            c2 = c;
                            r = 9;
                            c = 9;
                        }
                    }
                }
                if(r2 != -1 && c2 != -1)
                    solve(board, r2, c2);
                else
                    final = true;
                if(!final)
                    board[i][j] = '.';
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        int r2 = -1, c2 = -1;
        for(int r = 0; r < 9; r++)
        {
            for(int c = 0; c < 9; c++)
            {
                if(board[r][c] == '.')
                {
                    r2 = r;
                    c2 = c;
                    r = 9;
                    c = 9;
                }
            }
        }
        solve(board, r2, c2);
        
    }
};
