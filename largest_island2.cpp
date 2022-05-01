#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int i, int j, int m, int n) {
    visited[i][j] = true;

    int d_i[] = {0, 0, 1, -1};
    int d_j[] = {1, -1, 0, 0};

    int cnt = 1;

    for (int k = 0; k < 4; k++) {
        int n_i = d_i[k] + i;
        int n_j = d_j[k] + j;

        if ((n_i >= 0 && n_i < m) && (n_j >= 0 && n_j < n) && !visited[n_i][n_j] && matrix[n_i][n_j] == 1) {
            int subcomponent = dfs(matrix, visited, n_i, n_j, m, n);
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
                int size = dfs(matrix, visited, i, j, m, n);
                if (size > largest) largest = size;
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

   cout<< largestIsland(grid) <<endl;

    return 0;
}
