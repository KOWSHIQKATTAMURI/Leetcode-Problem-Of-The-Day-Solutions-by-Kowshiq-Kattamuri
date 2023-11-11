class Solution {
public:
    vector<int> ans;
    void dfs(int curr, int prev, unordered_map<int, vector<int>> &adj){
        ans.push_back(curr);
        for(int &v: adj[curr]){
            if(v != prev){
                dfs(v, curr, adj);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs){
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < adjacentPairs.size(); i++){
            int u = adjacentPairs[i][0];
            int v = adjacentPairs[i][1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        int start = -1;
        for(auto it : mp){
            if(it.second.size() == 1){
                start = it.first;
                break;
            }
        }
        dfs(start, INT_MIN, mp);
        return ans;
    }
};