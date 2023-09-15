class Solution {
public:
    vector<string> board;
    vector<vector<string>> ans;
    int N;

    bool isValid(int r, int c)
    {
        int i = r + 1, j = c;

        //column
        while(i % N != r)
        {
            if(board[i % N][j] == 'Q')
                return false;
            
            i++;
        }

        i = r + 1, j = c + 1;
        //45 degree
        while(i < N && j < N)
        {
            if(board[i][j] == 'Q')
                return false;
            i++;
            j++;
        }
        i = r - 1, j = c - 1;
        //45 degree
        while(i >= 0 && j >= 0)
        {
            if(board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }

        i = r - 1, j = c + 1;
        //135 degree
        while(i >= 0 && j < N)
        {
            if(board[i][j] == 'Q')
                return false;
            i--;
            j++;
        }

        i = r + 1, j = c - 1;
        //135 degree
        while(i < N && j >= 0)
        {
            if(board[i][j] == 'Q')
                return false;
            i++;
            j--;
        }

        return true;

    }

    void backT(int row)
    {
        if(row == N)
        {
            ans.push_back(board);
            return;
        }

        for(int j = 0; j < N; j++)
        {
            if(isValid(row, j))
            {
                board[row][j] = 'Q';
                backT(row+1);
                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        N = n;
        string r;
        for(int i = 0; i < n; i++)
            r.push_back('.');
        for(int i = 0; i < n; i++)
            board.push_back(r);
        
        backT(0);
        return ans;
    }
};
