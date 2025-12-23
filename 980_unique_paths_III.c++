#include<bits/stdc++.h>
using namespace std;

class Solution {
    int ans = 0;
    int m, n;
    int emptyCount = 0;

    void dfs(vector<vector<int>>& grid, int row, int col, int steps) {
        
        if(row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == -1) return;

    
        if(grid[row][col] == 2) {
            if(steps == emptyCount) ans++;
            return;
        }

        
        int temp = grid[row][col];
        grid[row][col] = -1; 

        
        
        dfs(grid, row+1, col, steps+1);
        dfs(grid, row-1, col, steps+1);
        dfs(grid, row, col+1, steps+1);
        dfs(grid, row, col-1, steps+1);

        
        grid[row][col] = temp;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int startRow, startCol;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) emptyCount++;
                else if(grid[i][j] == 1) {
                    startRow = i;
                    startCol = j;
                }
            }
        }

        
        emptyCount += 2;

        dfs(grid, startRow, startCol, 1);
        return ans;
    }
};
