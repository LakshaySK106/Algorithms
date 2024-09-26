#include <iostream>
#include <cstring>
using namespace std;
#define N 5
int row[] = { 2, 1, -1, -2, -2, -1, 1, 2, 2 };
int col[] = { 1, 2, 2, 1, -1, -2, -2, -1, 1 };
 
bool isValid(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= N) {
        return false;
    }
 
    return true;
}
 
void knightTour(int visited[N][N], int x, int y, int pos)
{
    visited[x][y] = pos;
    if (pos >= N*N)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++) {
                cout << visited[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        visited[x][y] = 0;
        return;
    }
    for (int k = 0; k < 8; k++)
    {
        int newX = x + row[k];
        int newY = y + col[k];
        if (isValid(newX, newY) && !visited[newX][newY]) {
            knightTour(visited, newX, newY, pos + 1);
        }
    }
    visited[x][y] = 0;
}
 
int main()
{
    int visited[N][N];
    memset(visited, 0, sizeof visited);
 
    int pos = 1;
    knightTour(visited, 0, 0, pos);
 
    return 0;
}
