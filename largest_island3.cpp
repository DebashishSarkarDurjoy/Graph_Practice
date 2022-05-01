#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int i, int j, int m, int n) {
    visited[i][j] = true;

    int cnt = 1;

    int di[] = {0,0,1,-1};
    int dj[] = {1, -1, 0, 0};

    for (int k = 0; k < 4; k++) {
        int ni = i + di[k];
        int nj = j + dj[k];

        if ( (ni >= 0 && ni < m) && (nj >= 0 && nj < n) && (!visited[ni][nj]) && (matrix[ni][nj] == 1) ) {
            int subcomponent = dfs(matrix, visited, ni, nj, m, n);
            cnt += subcomponent;
        }
    }

    return cnt;
}

int largestIsland(vector<vector<int>> matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int largest = 0;
    vector<vector<bool>> visited(m, vector<bool> (n, false));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && matrix[i][j] == 1) {
                int currentSize = dfs(matrix, visited, i, j, m, n);
                if (currentSize > largest) largest = currentSize;
            }
        }
    }

    return largest;
}

int main(void) {
    vector<vector<int> > grid = {
                           {1, 0, 1, 1, 0},
                           {1, 0, 1, 0, 0},
                           {0, 0, 1, 0, 1},
                           {1, 0, 1, 1, 1},
                           {1, 0, 1, 1, 0}
                           };

   cout<< largestIsland(grid) <<endl;

    return 0;
}
