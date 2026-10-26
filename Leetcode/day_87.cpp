#include <vector>

using namespace std;

class Solution {
private:
    long long dfs(int r, int c, int rows, int cols, vector<vector<int>>& grid) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) {
            return 0;
        }

        long long currentVal = grid[r][c];
        grid[r][c] = 0; // Mark as visited

        currentVal += dfs(r + 1, c, rows, cols, grid);
        currentVal += dfs(r - 1, c, rows, cols, grid);
        currentVal += dfs(r, c + 1, rows, cols, grid);
        currentVal += dfs(r, c - 1, rows, cols, grid);

        return currentVal;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int validIslandsCount = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] > 0) {
                    long long islandSum = dfs(r, c, rows, cols, grid);
                    if (islandSum % k == 0) {
                        validIslandsCount++;
                    }
                }
            }
        }

        return validIslandsCount;
    }
};