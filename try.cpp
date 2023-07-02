class Solution
{
public:
    bool dfs(vector<vector<char>> &m, int row, int col, int i, int j)
    {
        if (i < 0 or i >= row or j < 0 or j >= col)
        {
            return false;
        }
        else if (m[i][j] == 'X')
        {
            return true;
        }
        else
        {
            // its an O hence we return the status of the current O
            bool res = dfs(m, row, col, i - 1, j) & dfs(m, row, col, i + 1, j) & dfs(m, row, col, i, j - 1) & dfs(m, row, col, i, j + 1);
            if (res == true)
            {
                m[i][j] = 'X';
            }
            return res;
        }
    }

    void solve(vector<vector<char>> &board)
    {
        int row = board.size();
        int col = board[0].size();
        
    }
};