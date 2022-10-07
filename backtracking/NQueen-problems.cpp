class Solution
{
public:
    bool issafe(vector<string> &board, int row, int col, int n)
    {
        int x = row;
        int y = col;

        // check for collumn

        while (x >= 0)
        {
            if (board[x][y] == 'Q')
                return false;
            x--;
        }

        // check for upper diagonal

        x = row;
        y = col;
        while (x >= 0 && y >= 0)
        {
            if (board[x][y] == 'Q')
                return false;
            x--;
            y--;
        }

        // check for lower diagonal

        x = row;
        y = col;
        while (y < n && x >= 0)
        {
            if (board[x][y] == 'Q')
                return false;
            x--;
            y++;
        }
        return true;
    }
    void solve(vector<string> &board, vector<vector<string>> &ans, int row, int n)
    {
        if (row == n)
        {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (issafe(board, row, col, n))
            {
                board[row][col] = 'Q';
                solve(board, ans, row + 1, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        if (n == 1)
        {
            return {{"Q"}};
        }
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        int row = 0;
        solve(board, ans, row, n);
        return ans;
    }
};