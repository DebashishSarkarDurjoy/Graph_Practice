#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j, int m, int n) {
    visited[i][j] = true;

    int di[] = {1, -1, 0, 0};
    int dj[] = {0, 0, 1, -1};

    int cs = 1;

    for (int k = 0; k < 4; k++) {
        int ni = i + di[k];
        int nj = j + dj[k];

        if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj] && grid[ni][nj] == 1) {
            cout << ni << " " << nj << endl;
            int subCom = dfs(grid, visited, ni, nj, m, n);
            cs += subCom;
        }
    }

    return cs;
}

int largest_island(vector<vector<int>> &grid) {
    int largest = INT_MIN;

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool> (n, false));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                int currentSize = dfs(grid, visited, i, j, m, n);
                if (currentSize > largest) {
                    largest = currentSize;
                }
            }
        }
    }
    return largest;
}


int main(void) {
    vector<vector<int> > grid = {
                           {1, 0, 0, 1, 0},
                           {1, 0, 1, 0, 0},
                           {0, 0, 1, 0, 1},
                           {1, 0, 1, 1, 1},
                           {1, 0, 1, 1, 0}
                           };

   cout<< largest_island(grid) <<endl;

    return 0;
}
