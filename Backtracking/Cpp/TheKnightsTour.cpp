#include <bits/stdc++.h>
using namespace std;

void solve(int n, int i, int j, int cnt, vector<vector<int>> &mat, vector<vector<bool>> &visited)
{
    if (i < 0 || j < 0 || i >= n || j >= n)
        return;

    if (visited[i][j])
        return;

    if (cnt == (n * n - 1))
    {
        mat[i][j] = cnt;
        return;
    }

    visited[i][j] = true;
    mat[i][j] = cnt;
    solve(n, i - 2, j + 1, cnt + 1, mat, visited);
    solve(n, i - 2, j - 1, cnt + 1, mat, visited);
    solve(n, i + 2, j + 1, cnt + 1, mat, visited);
    solve(n, i + 2, j - 1, cnt + 1, mat, visited);
    solve(n, i - 1, j + 2, cnt + 1, mat, visited);
    solve(n, i - 1, j - 2, cnt + 1, mat, visited);
    solve(n, i + 1, j + 2, cnt + 1, mat, visited);
    solve(n, i + 1, j - 2, cnt + 1, mat, visited);
    visited[i][j] = false;
    mat[i][j] = 0;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n, 0));

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    solve(n, 0, 0, 0, mat, visited);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
