class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads){
        vector<int> degree(n, 0);
        vector<vector<int>> grid(n + 1, vector<int>(n + 1, false));
        for(auto it : roads){
            degree[it[0]]++;
            degree[it[1]]++;
            grid[it[0]][it[1]] = true;
            grid[it[1]][it[0]] = true;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                ans = max(ans, degree[j] + degree[i] - grid[i][j]);
            }
        }
        return ans;
    }
};