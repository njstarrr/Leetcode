class Solution {
public:
    int countIslands(std::vector<std::vector<int>>& grid, int k) {
        if (grid.empty() || grid[0].empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        auto dfs = [&](auto& self, int r, int c) -> long long {
            if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0) {
                return 0;
            }

            long long val = grid[r][c];
            grid[r][c] = 0;

            return val + self(self, r + 1, c) 
                       + self(self, r - 1, c) 
                       + self(self, r, c + 1) 
                       + self(self, r, c - 1);
        };

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] > 0) {
                    long long island_sum = dfs(dfs, r, c);
                    if (island_sum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};