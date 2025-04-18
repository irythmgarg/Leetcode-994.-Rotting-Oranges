class Solution {
public:
    // Helper function to check if a cell is within bounds and contains a fresh orange (1)
    bool isok(int i, int j, int m, int n, vector<vector<int>>& grid) {
        return i >= 0 && j >= 0 && i < m && j < n && grid[i][j] == 1;
    }

    // Main function to determine the minimum time needed to rot all oranges
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Queue for BFS: stores {time, {i, j}}
        queue<pair<int, pair<int, int>>> q;

        // Step 1: Push all initially rotten oranges into the queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({0, {i, j}});
                }
            }
        }

        int maxans = 0; // Maximum time to rot all oranges

        // Step 2: Perform BFS to rot all reachable fresh oranges
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto top = q.front();
                q.pop();

                maxans = max(maxans, top.first); // Update max time

                int i = top.second.first;
                int j = top.second.second;

                // Check 4 directions: Down, Right, Up, Left
                vector<pair<int, int>> dire = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
                for (int p = 0; p < 4; p++) {
                    int u = i + dire[p].first;
                    int v = j + dire[p].second;

                    if (isok(u, v, m, n, grid)) {
                        grid[u][v] = 2; // Rot the fresh orange
                        q.push({top.first + 1, {u, v}});
                    }
                }
            }
        }

        // Step 3: Check if any fresh oranges remain
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) return -1; // Impossible to rot all
            }
        }

        return maxans;
    }
};
