class Solution {
    int directions[4][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
public:
    int numIslands(vector<vector<char>>& grid) {
        // first we need the number of rows and columns
        int ROWS = grid.size(), COLS = grid[0].size();
        int island = 0;

        // now we iterate starting from the initial cell
        for (int r = 0; r < ROWS; ++r){
            for (int c = 0; c < COLS; ++c) {
                // we start dfs only if it's 1
                if (grid[r][c] == '1') {
                    dfs(grid, r, c);
                    island++; // at this point we found the island starting at r,c
                }
            }
        }

        return island;
    }

    void dfs(vector<vector<char>>& grid, int r, int c) {
        // we check if the position is valid
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0') {
            return;
        }

        // check all the 4 cells adjacent
        grid[r][c] = '0'; // we need to update the cell so that we don't have infinite loop

        for (int i = 0; i < 4; ++i) {
            dfs(grid, r + directions[i][0], c + directions[i][1]);
        }
    }
};
