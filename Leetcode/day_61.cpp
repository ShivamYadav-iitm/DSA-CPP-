#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if ((m + n - 1) % 2 != 0) {
            return false;
        }
        
        if (grid[0][0] == ')' || grid[m-1][n-1] == '(') {
            return false;
        }
        
        int max_balance = (m + n) / 2;
      
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(max_balance + 1, -1)));
        
        return dfs(grid, 0, 0, 0, memo);
    }
    
private:
    bool dfs(vector<vector<char>>& grid, int r, int c, int balance, vector<vector<vector<int>>>& memo) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (grid[r][c] == '(') {
            balance++;
        } else {
            balance--;
        }
        
       
        int remaining_steps = (m - 1 - r) + (n - 1 - c);
        if (balance < 0 || balance > remaining_steps) {
            return false;
        }
        
        if (r == m - 1 && c == n - 1) {
            return balance == 0;
        }
        
        if (memo[r][c][balance] != -1) {
            return memo[r][c][balance] == 1;
        }
        
        bool isValid = false;
        if (r + 1 < m) {
            isValid = isValid || dfs(grid, r + 1, c, balance, memo);
        }
        if (!isValid && c + 1 < n) {
            isValid = isValid || dfs(grid, r, c + 1, balance, memo);
        }
        
        memo[r][c][balance] = isValid ? 1 : 0;
        return isValid;
    }
};