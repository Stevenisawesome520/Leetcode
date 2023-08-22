class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matirx(n, vector<int>(n, 0));

        int i = 0, j = 0;
        bool _i = true, i_ = false, _j = false, j_ = false;
        for(int k = 1; k <= n*n; k++)
        {
            matirx[j][i] = k;
            if(_i && (i+1 > n-1 || (i <= n-2 && matirx[j][i+1])))
            {
                _i = false;
                _j = true;
                //j++;
            }
            else if(_j && (j+1 > n-1 || (j <= n-2 && matirx[j+1][i])))
            {
                _j = false;
                i_ = true;
                //i--;
            }
            else if(i_ && (i-1 < 0 || ( i > 0 && matirx[j][i-1])))
            {
                i_ = false;
                j_ = true;
                //j--;
            }
            else if(j_ && (j-1 < 0 || ( j > 0 && matirx[j-1][i])))
            {
                j_ = false;
                _i = true;
                //i++;
            }

            if(_i)
                i++;
            else if(_j)
                j++;
            else if(i_)
                i--;
            else if(j_)
                j--;
        }

        return matirx;
    }
};
