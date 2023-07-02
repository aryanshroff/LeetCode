class Solution
{
public:
    int dfs(vector<vector<int>> &grid, int row, int col, int i, int j)
    {
        if (i < 0 or i > row or j < 0 or j > col)
        {
            return 0;
        }
        else if (grid[i][j] == 0)
            return;
        else
        {
            // reached here means its 1

            // make it 0
            grid[i][j] = 0;
            // make dfs calls on it
            return 1 + dfs(grid, row, col, i - 1, j) + dfs(grid, row, col, i + 1, j) + dfs(grid, row, col, i, j - 1) + dfs(grid, row, col, i, j + 1);
        }
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        int maxArea = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j)
            {
                if (grid[i][j] == 1)
                {
                    maxArea = max(maxArea, dfs(grid, row, col, i, j));
                }
            }
        }
        return maxArea;
    }
};