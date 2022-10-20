class Solution {
public:
    int path(vector<vector<int>>&grid,int m,int n,int i,int j,vector<vector<int>>&dp)
    {
        if(i == 0 && j == 0)
              return grid[i][j];
        if(!(i>=0 && i<=m-1) || !(j >= 0 && j <= n-1))
            return 1e9;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int left = grid[i][j] + path(grid,m,n,i-1,j,dp);
        int right = grid[i][j] + path(grid,m,n,i,j-1,dp);
        return dp[i][j]=min(left,right);
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return path(grid,m,n,m-1,n-1,dp);
    }
};
